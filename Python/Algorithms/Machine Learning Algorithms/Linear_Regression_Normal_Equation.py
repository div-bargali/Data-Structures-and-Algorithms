import numpy as np
import pandas as pd


def model(x, parameter):
	# A hypothesis Function h(x)
    h = 0
    for i in range(0, len(parameter)):
        h = h + (x[i] * parameter[i])
    return h


# Reading Dataset
dataset = pd.read_csv('data.csv', header=None)

# Getting Features
features_temp = dataset.iloc[:, :-1]

# Adding Bias term to the dataframe at index 0
bias_term = ['1'] * len(dataset)
bias_term = [int(i) for i in bias_term]
features = pd.DataFrame(bias_term)
for i in range(0, features_temp.shape[1]):
    features[i + 1] = features_temp.iloc[:, i]

# Getting Outputs
labels = dataset.iloc[:, -1]
# print(features.head())
# print(labels.head())

# Converting Everything to NumPy for matrix multiplication and inverse calculation
features = features.to_numpy()
labels = labels.to_numpy()

#Normal Equation Formula = inverse_of(product_of(X.T, X)) * product_of(X.T, Y)

# Taking transpose of features
features_t = features.T

# Taking Inverse
temp = np.linalg.pinv(np.dot(features_t, features))

temp2 = np.dot(features_t, labels)
parameters = np.dot(temp, temp2)
print(parameters)

# Price Prediction
size = input("Enter The Size of house: ")
beds = input("Enter The Number of beds: ")
print(model([1, int(size), int(beds)], parameters))