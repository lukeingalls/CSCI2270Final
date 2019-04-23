import numpy as np
import requests
from scipy import stats
import pandas as pd
import urllib.request
import csv
from bs4 import BeautifulSoup
import matplotlib.pyplot as plt


urls = []
for i in range(2007, 2019):
    url = 'https://www.basketball-reference.com/draft/NBA_'+str(i)+'.html'
    urls.append(url)
    
ranking = [[],[]]
for url in urls:
    response = requests.get(url)
    soup = BeautifulSoup(response.text, 'html.parser')
    table = soup.find('tbody')
    row = table.findAll('tr')
    for r in row:
        player = []
        items = r.findAll('td')
        if len(items) > 2:
            if items[0] and items[2]:
                player.append(items[0].get_text())
                player.append(items[2].get_text())
                ranking.append(player)
            
with open("drafts.csv", "w") as f:
    writer = csv.writer(f)
writer.writerows(ranking)