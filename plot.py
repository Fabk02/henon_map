import matplotlib.pyplot as plt
import numpy as np
import os

dir_name = "data"
dir = os.fsencode(dir_name)

for file in os.listdir(dir):
    filename =  os.fsdecode(file)
    X, Y = np.loadtxt(dir_name + "/" + filename, delimiter=';', unpack=True)

    plt.title(filename.split("_")[0])
    plt.scatter(X,Y,s=5)
    plt.savefig("graphs/" + filename.split("_")[0] + "_graph.png")
    plt.close()