import numpy as np
import requests
from scipy import stats
import pandas as pd
import urllib.request
import time
from bs4 import BeautifulSoup
import matplotlib.pyplot as plt
import time

urls = []
stats = ["points", "assists", "rebounds", "steals", "turnovers", "blocks"]
start = time.time()
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
    print ('Running... time elapsed: ' + str(time.time() - start))

print('Done! time elapsed: ' + str(time.time()-start) + ' Read in ' + str(len(urls)) + ' links')

player_file = open("revised_players.txt", "w")
start = time.time()
for i in range(len(urls)):
    url = urls[i]
    response = requests.get(url)
    soup = BeautifulSoup(response.text, 'html.parser')
    name = soup.find(id = 'h1-title')
    name1 = name.get_text()
    if (name1 != 'NCAA Players'):
        player_file.write(str(name1) + "\n")
        bio = soup.find(class_ = 'h1-sub')
        bio1 = bio.get_text()#.strip()
        player_file.write(str(bio1) + "\n")
        table = soup.find('tbody')
        table1 = table.findAll('td')
        table2 = []
        for x in table1:
            player_file.write(str(x.get_text().strip()) + ",")
        player_file.write("\n ------------------ \n")
    x = time.time() - start
    print ('Running... time elapsed: ' + str(x) + '   Percent Complete: ' + str(i*100/len(urls)))
