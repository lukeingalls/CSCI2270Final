import csv

mess = open("Raw Players.txt", "r")

delim = True
pos = False
height_weight = False

player_bio = []

tr = [[],[]]
te = [[],[]]
pr = [[],[]]


for line in mess:
    line = line.strip()
    if line:
        if ("------------------" in line): #Check and reset at a delimiter
            if (player_bio[len(player_bio)-12] == '2019'):
                print('2019')
                pr.append(player_bio[len(player_bio) - 16:])
            elif (player_bio[len(player_bio)-12] == '2018'):
                print('2018')
                te.append(player_bio[len(player_bio) - 16:])
            else:
                print('default')
                tr.append(player_bio[len(player_bio) - 16:])
            
            delim = True
            pos = False
            height_weight = False
        elif (delim): #Check if the name has been pulled
                player_bio.append(line)
                delim = False
        elif ('#' in line and not pos): #Check if Position has been pulled
            x = line.split()
            player_bio.append(x[1])
            pos = True
        elif (not height_weight and '"' in line):
            x = line.split()
            player_bio.append(x[0])
            player_bio.append(x[1])
            height_weight = True
        elif (height_weight and '|' not in line):
            delim = False
            x = line.split(',')
            x = x[:len(x)-1]
            player_bio.append(x[0][5:])
            player_bio.append(x[1])
            avg = [0] * 9
            y = len(x)//11
            z = y
            for i in range(0, y):
                if ('-' in x[2+i*11]):
                    i +=1
                    z -= 1
                    if i >= y:
                        break
                else:
                    avg[0] += float(x[2+i*11])/y
                    avg[1] += float(x[3+i*11])/y
                    avg[2] += float(x[4+i*11])/y
                    avg[3] += float(x[5+i*11])/y
                    avg[4] += float(x[6+i*11])/y
                    avg[5] += float(x[7+i*11])/y
                    avg[6] += float(x[8+i*11])/y
                    avg[7] += float(x[9+i*11])/y
                    avg[8] += float(x[10+i*11])/y
            for i in avg:
                player_bio.append(i)
                
            player_bio.append(z)
                                
  