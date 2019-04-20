import numpy as np
import requests
from scipy import stats
import pandas as pd
import urllib.request
import time
from bs4 import BeautifulSoup
import matplotlib.pyplot as plt

urls = []
for i in range(2007, 2019):
    url = 'https://stats.nba.com/draft/history/?Season='+str(i)
    urls.append(url)
print(urls[0])

ranking = [[],[]]
for i in range(len(urls)):
    player = []
    url = urls[i]
    response = requests.get(url)
    soup = BeautifulSoup(response.text, 'html.parser')
    table = soup.find('tbody')
    rows = table.findAll('tr')
    for j in rows:
        name = j.find(class_ = 'player')
        name1 = name.get_text()
