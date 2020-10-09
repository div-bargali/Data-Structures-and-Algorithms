#!/usr/bin/env python
# coding: utf-8

# In[16]:


#importing required packages
import pandas as pd
from sklearn import preprocessing
from sklearn.model_selection import train_test_split
from sklearn.naive_bayes import GaussianNB
from sklearn.metrics import accuracy_score
from sklearn.metrics import confusion_matrix
from sklearn.naive_bayes import BernoulliNB
clf=BernoulliNB()

#loading the data
dataset=pd.read_csv("C:/Users/ASUS/Downloads/train.csv")
dataset.head()

#getting the description of the dataset
dataset.describe()
dataset.describe().sum()

#get some info about the data
dataset.info()

#getting the amount of null values in each column
dataset.isnull().sum()

#dropping the unimportant columns

dataset=dataset.drop('PassengerId', axis=1)

dataset=dataset.drop('Name', axis=1)

dataset=dataset.drop('Ticket', axis=1)

dataset=dataset.drop('Cabin', axis=1)

dataset.head()

#label encoding the categorical values which are of object type 
le=preprocessing.LabelEncoder()
dataset['Sex']=le.fit_transform(dataset['Sex'])
dataset['Embarked']=le.fit_transform(dataset['Embarked'])
dataset.head()

"""this functions takes the independent variable column and trains the model after dividing the dataset into x and y
and also spliting the dataset into training and testing data.This also prints the accuracy score and the confusion matrix"""
 
def navbaiyes(value):
    x=dataset.drop([value], axis=1)
    y=dataset[value]
    x_train,x_test,y_train,y_test=train_test_split(x,y,test_size=0.2,random_state=0)
    
    
    y_pred= clf.fit(x_train,y_train).predict(x_test)
    print("The accuracy score is:")
    print(accuracy_score(y_test, y_pred)*100)
    print('--------------------------------------------')
    print("The confusion matrix is:")
    print(confusion_matrix(y_test,y_pred))
    
#Calling the function
navbaiyes('Survived')


# In[ ]:




