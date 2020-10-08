## Fashion - MNIST dataset is present in Keras
## You need to install Keras , Tensorflow , Numpy ,matplotlib and Sklearn to run this on your machine
from keras.datasets import fashion_mnist
from keras.models import Sequential
from keras.layers import Dense, Dropout, Flatten
from keras.layers import Conv2D, MaxPooling2D
import numpy as np
## Use https://keras.io/datasets/ 
samples=fashion_mnist.load_data()
type(samples)
## This dataset is a set of 2 tuples. One for Training and other for testing
(Train_samples,Train_targets),(Test_samples,Test_targets)=samples
# Step 1 : Know your data
print(len(Train_samples))
print(Train_samples.shape)
print(len(Train_targets))
print(Train_targets.shape)
print(len(Test_samples))
print(Test_samples.shape)
print(len(Test_targets))
print(Test_targets.shape)
print(np.amax(Train_samples)) # Max value
print(np.amin(Train_samples))#Min Value

# Commented out IPython magic to ensure Python compatibility.
# Step 2 : See how data looks like
# %matplotlib inline
import matplotlib.pyplot as plt
for i in range(10):
  pixels = Train_samples[i] # Shape (28, 28)
  plt.imshow(pixels, cmap='gray')
  plt.show()
  print('Label of image is', Train_targets[i])

# Step 3 : Reshape the data . 1 at last signifies that it's a grey scale image. 3 is used for RGB images.
Train_samples=Train_samples.reshape(Train_samples.shape[0], 28, 28, 1)
Test_samples =Test_samples.reshape(Test_samples.shape[0], 28, 28, 1)

# Step 4 : Scaling the input features between 0-1
Train_samples=Train_samples/255
Test_samples =Test_samples/255

# Step 6 : One-Hot Encoding
from keras.utils import to_categorical
Train_targets = to_categorical(Train_targets,num_classes=10)
Test_targets = to_categorical(Test_targets,num_classes=10)

# Step 7 : Creating the model
model = Sequential()
model.add(Conv2D(32, kernel_size=(3, 3),activation='relu',input_shape=(28,28,1)))
model.add(Conv2D(64, kernel_size=(3, 3), activation='relu'))
model.add(MaxPooling2D(pool_size=(2, 2)))
model.add(Dropout(0.3))
model.add(Flatten())
model.add(Dense(256, activation='relu'))
model.add(Dropout(0.5))
model.add(Dense(10, activation='softmax'))
model.compile(optimizer='adam',loss=['categorical_crossentropy'],metrics=['accuracy'])

# Step 8 : Understanding the model
model.summary()

# Step 9 : Training the model
model.fit(Train_samples,Train_targets, validation_split = 0.1, epochs=10, batch_size=1000,verbose=1)

# Step 10 : Testing the model
testing=model.evaluate(Test_samples,Test_targets)
print("\n%s: %.2f%%" % (model.metrics_names[1]+'uracy of Model on testing data', testing[1]*100))

#Step 11 : Evaluate teh model 
##Compute a confusion matrix for each class or sample (0-9)
from sklearn.metrics import multilabel_confusion_matrix 
predictions=np.round(model.predict(Test_samples))
print(multilabel_confusion_matrix(Test_targets,predictions))