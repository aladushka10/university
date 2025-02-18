import matplotlib.pylab as wndpl
import matplotlib.pyplot as plt
import numpy as np
import os
import math

#plt.style.use('_mpl-gallery')

for file_name in os.listdir():
    if file_name.endswith('.txt'):
        file_path = os.path.join('', file_name)
        x = []
        y = []
        with open(file_path) as f:
            for line in f:
                data = line.split()
                x.append(float(data[0]))
                y.append(float(data[1]))

        plt.xscale('log')

        plt.clf()
        plt.plot(x, y, color="red", linewidth = '2')  # marker='o' для отображения точек на графике
        x = np.linspace(0, 1, 10000)
        y = np.sin(0.5 * x) + x ** 3
        plt.plot(x, y, color="blue", linewidth = '3', linestyle = ":")
        plt.xlabel('X')
        plt.ylabel('Y')
        plt.grid(True)
        fig = wndpl.gcf()
        fig.canvas.manager.set_window_title(file_path[:file_path.find('.')])
        plt.show()
        plt.clf()
