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

all = [[],[]]
start = time.time()
for i in range(len(urls)):
    player = []
    url = urls[i]
    response = requests.get(url)
    soup = BeautifulSoup(response.text, 'html.parser')
    name = soup.find(id = 'h1-title')
    name1 = name.get_text()
    if (name1 == 'NCAA Players'):
        del urls[i]
    else:
        bio = soup.find(class_ = 'h1-sub')
        bio1 = bio.get_text()#.strip()
        table = soup.find('tbody')
        table1 = table.findAll('td')
        table2 = []
        for x in table1:
            table2.append(x.get_text().strip())  
        player.append(name1)
        player.append(bio1)
        player.append(table2)
        all.append(player)
    if (i//100 == i/100):
        x = time.time() - start
        y = (len(urls)/(i + 1))*(x)
        print ('Running... time elapsed: ' + str(x) + '   Estimated time remaining: ' + str(y))

        
output = open("players.txt", 'w')

for i in range len(all):
    for j in range len(all[i]):
        ouput.write(all[i][j] + "\n")
    output.write("---------------------------------------")
