## Step 1: Import Libraries
import matplotlib.pyplot as plt #For plotting 
import pandas as pd 
from sklearn import datasets #For getting dataset
## Step 2: Get data
iris = datasets.load_iris()
data = pd.DataFrame(iris.data,columns= iris.feature_names)
print(data.head())
## Step 3: Manipulate data
x = data.iloc[:, [0, 1, 2, 3]].values
## Step 4: Apply Kmeans function
from sklearn.cluster import KMeans #Kmeans algo is present in this library
inertia_values = []
for i in range(1, 10):
    kmeans = KMeans(n_clusters = i, init = 'k-means++', max_iter = 300, n_init = 10, random_state = 0)
    kmeans.fit(x)
    inertia_values.append(kmeans.inertia_)
plt.plot(range(1,i+1),inertia_values)
plt.xlabel('Number of Clusters')
plt.ylabel('Inertia Values')
plt.title('Elbow Method for optimum number of clusters')
plt.show()
'''
To determine the optimal number of clusters, select the value of k at the “elbow” i.e. the point after which the inertia start decreasing in a linear fashion.
Thus for the given data, we conclude that the optimal number of clusters for the data is 3.
'''
## Step 5: Visualize Clusters
# So, now you have found how many clusters can be made from dataset . Now, we move to visualization.
kmeans = KMeans(n_clusters = 3, init = 'k-means++',max_iter = 300, n_init = 10, random_state = 0)
y_kmeans = kmeans.fit_predict(x)
plt.scatter(x[y_kmeans == 0, 0], x[y_kmeans == 0, 1], s = 50, c = 'lightcoral', label = 'Iris-setosa') # Flower names can be seen in description
plt.scatter(x[y_kmeans == 1, 0], x[y_kmeans == 1, 1], s = 50, c = 'lightblue', label = 'Iris-versicolour')
plt.scatter(x[y_kmeans == 2, 0], x[y_kmeans == 2, 1],s = 50, c = 'silver', label = 'Iris-virginica')
#I've plotted this based on sepal length and sepal width . 
plt.xlabel('Sepal Length')
plt.ylabel('Sepal Width')
plt.title('Clusters in Iris Data')
plt.scatter(kmeans.cluster_centers_[0,0],kmeans.cluster_centers_[0,1],label ='Setosa_Centroid',c='red',s=70 )
plt.scatter(kmeans.cluster_centers_[1,0],kmeans.cluster_centers_[1,1],label ='Versicolor_Centroid',c='Blue',s=70 )
plt.scatter(kmeans.cluster_centers_[2,0],kmeans.cluster_centers_[2,1],label ='Virginica_Centroid',c='black',s=70 )
plt.show()