import numpy as np
import requests
from scipy import stats
import pandas as pd
import urllib.request
import time
from bs4 import BeautifulSoup
import matplotlib.pyplot as plt
# from sklearn.model_selection import train_test_split
# from sklearn.linear_model import LogisticRegression
urls = []
for i in range(2002,2018):
    url = 'http://www.espn.com/mens-college-basketball/statistics/player/_/stat/scoring-per-game/sort/avgPoints/year/'+str(i)+'/seasontype/2'
    response = requests.get(url)
    # print(response) #successful
    soup = BeautifulSoup(response.text, 'html.parser')
    table = soup.find('table')

    rows = table.findAll('tr')
    for row in rows:
        x = row.find('a', href=True)['href']
        if x != '//www.espn.com/mens-college-basketball/statistics/player/_/stat/scoring-per-game/sort/avgPoints/year/'+str(i)+'/seasontype/2/order/false':
            urls.append(x)

for i in range(2002,2018):
    url = 'http://www.espn.com/mens-college-basketball/statistics/player/_/stat/scoring-per-game/sort/avgPoints/year/'+str(i)+'/seasontype/2/count/41'
    response = requests.get(url)
    # print(response) #successful
    soup = BeautifulSoup(response.text, 'html.parser')
    table = soup.find('table')

    rows = table.findAll('tr')
    for row in rows:
        x = row.find('a', href=True)['href']
        if x != '//www.espn.com/mens-college-basketball/statistics/player/_/stat/scoring-per-game/sort/avgPoints/year/'+str(i)+'/seasontype/2/order/false':
            urls.append(x)
            
for i in range(2002,2018):
    url = 'http://www.espn.com/mens-college-basketball/statistics/player/_/stat/scoring-per-game/sort/avgPoints/year/'+str(i)+'/seasontype/2/count/81'
    response = requests.get(url)
    # print(response) #successful
    soup = BeautifulSoup(response.text, 'html.parser')
    table = soup.find('table')

    rows = table.findAll('tr')
    for row in rows:
        x = row.find('a', href=True)['href']
        if x != '//www.espn.com/mens-college-basketball/statistics/player/_/stat/scoring-per-game/sort/avgPoints/year/'+str(i)+'/seasontype/2/order/false':
            urls.append(x)
            
for u in urls:
    print(u)   
