import matplotlib.pyplot as plt
import csv
import numpy as np

X, Y = np.loadtxt('data.txt', delimiter=';', unpack=True)
plt.plot([],[], 'bo')

for i in range(len(X)):
    plt.plot(X[:i +1], Y[:i +1], 'bo')
    plt.pause(0.05)

plt.show()



