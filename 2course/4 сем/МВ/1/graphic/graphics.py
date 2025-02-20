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
        plt.plot(x, y, color="blue")  # marker='o' для отображения точек на графике
        x = np.linspace(-3, 3, 10000)
        if '1' in file_path.split('_')[0]:
            y = np.exp(np.sin(x))
        else:
            y = abs(2 * np.sin(2 * x) - 1)
        plt.plot(x, y, color="red")
        plt.xlabel('X')
        plt.ylabel('Y')
        plt.grid(True)
        fig = wndpl.gcf()
        fig.canvas.manager.set_window_title(file_path[:file_path.find('.')])
        plt.show()
        plt.clf()
