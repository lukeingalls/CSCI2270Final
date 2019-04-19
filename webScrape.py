import numpy as np
import requests
from scipy import stats
import pandas as pd
import urllib.request
import time
from bs4 import BeautifulSoup
import matplotlib.pyplot as plt

urls = []
stats = ["points", "assists", "rebounds", "steals", "turnovers", "blocks"]
for j in stats:
    for i in range(304,316):
        url = 'https://www.teamrankings.com/ncaa-basketball/player-stat/'+j+'?season_id='+str(i)
        response = requests.get(url)
        # print(response) #successful
        soup = BeautifulSoup(response.text, 'html.parser')
        table = soup.find('table')
        rows = table.findAll('tr')
        rows = rows[1:]
        for row in rows:
            x = row.find('a', href=True)['href']
            urls.append('https://www.teamrankings.com'+x)
print(len(urls))

all = [[],[]]
for i in range(len(urls)):
    player = []
    url = urls[i]
    response = requests.get(url)
    soup = BeautifulSoup(response.text, 'html.parser')
    name = soup.find(id = 'h1-title')
    name1 = name.get_text()
    bio = soup.find(class_ = 'h1-sub')
    bio1 = bio.get_text().strip()
    table = soup.find('tbody')
    table1 = table.findAll('td')
    table2 = []
    for i in table1:
        table2.append(i.get_text().strip())  
    player.append(name1)
    player.append(bio1)
    player.append(table2)
    all.append(player)
