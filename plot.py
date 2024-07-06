import matplotlib.pyplot as plt
import numpy as np

X, Y = np.loadtxt('data.txt', delimiter=';', unpack=True)

plt.scatter(X,Y,s=5)
plt.show()