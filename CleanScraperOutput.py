mess = open("test_clean_up.txt", "r")
clean = open("cleaned_file", "w")

delimiter_flag = True
position_flag = False
height_flag = False
stat_flag = False

for line in mess:
    l = line.strip()
    if l:
        if "------------------" in l:
            delimiter_flag = True
            position_flag = False
            height_flag = False
            stat_flag = False
            clean.write("\n")
        elif delimiter_flag:
            clean.write(l + ",")
            delimiter_flag = False
        elif (position_flag == False and "#" in l):
            position_flag = True
            x = l.split()
            clean.write(x[1] + ",")
        elif (height_flag == False and "'" in l):
            x = l.split()
            height_flag = True
            clean.write(x[0] + ",")
            clean.write(x[1] + "\n")
        elif (height_flag == True and stat_flag == False and "|" not in l):
            x = l.split(",")
            for i in range(0, len(x), 11):
                s = x[i]
                x[i] = s[5:]
            for i in range(len(x)):
                clean.write(str(x[i]))
                if ((i + 1) % 11 == 0):
                    clean.write("\n")
                elif (i != len(x) - 1):
                    clean.write(",")
        
mess.close()
clean.close()
