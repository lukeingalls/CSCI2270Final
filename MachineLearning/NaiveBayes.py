import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import time
from sklearn.model_selection import train_test_split
from sklearn.naive_bayes import GaussianNB, BernoulliNB, MultinomialNB

# Importing dataset
data = pd.read_csv("output_train.csv")
other_data = pd.read_csv("output_test.csv")

# Convert categorical variable to numeric
data["Pos_Num"]=np.where(data["Position"]=="Guard",1,np.where(data["Position"]=="Forward",2,3))
other_data["Pos_Num"]=np.where(other_data["Position"]=="Guard",1,np.where(other_data["Position"]=="Forward",2,3))

other_data=other_data[[
    "Pos_Num",
    "Years",
    "Height",
    "Weight",
    "Games",
    "Minutes",
    "Points",
    "Rebounds",
    "Assists",
    "Steals",
    "Blocks",
    "Turnovers",
    "Fouls",
    "Draft_Status"
]].dropna(axis=0, how='any')
print(data)

data=data[[
    "Pos_Num",
    "Years",
    "Height",
    "Weight",
    "Games",
    "Minutes",
    "Points",
    "Rebounds",
    "Assists",
    "Steals",
    "Blocks",
    "Turnovers",
    "Fouls",
    "Draft_Status"
]].dropna(axis=0, how='any')

used_features =[
    "Pos_Num",
    "Years",
    "Height",
    "Weight",
    "Games",
    "Minutes",
    "Points",
    "Rebounds",
    "Assists",
    "Steals",
    "Blocks",
    "Turnovers",
    "Fouls"
]

X_values_train= data["Draft_Status"]
X_values_test = other_data["Draft_Status"]
# Split dataset in training and test datasets
X_train = data[used_features]
X_test = other_data[used_features]

gnb = GaussianNB()

# Train classifier
gnb.fit(
    X_train.values,
    X_values_train
)
y_pred = gnb.predict(X_test)

# Print results
print(y_pred)
print(len(y_pred))


print("Number of mislabeled points out of a total {} points : {}, performance {:05.2f}%"
      .format(
          X_test.shape[0],
          (X_values_test != y_pred).sum(),
          100*(1-(X_values_test != y_pred).sum()/X_test.shape[0])
))
