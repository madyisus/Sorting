import matplotlib.pyplot as plt
import pandas as pd
import numpy as np
import sys

data = sys.argv[1:]

fig = plt.figure('Resultados',figsize= (16,6),tight_layout=True)
ax1 = fig.add_subplot(1,2,1)
ax2 = fig.add_subplot(1,2,2)


for file in data:
    df = pd.read_csv(file)
    label = file.split('_')[0]
    x = df['n'].values
    y = df['time[ms]'].values
    ax1.plot(x, y, label=label)

    # if label in ['bubblesort','selectionSort','quicksort']:
    #     coef = np.polyfit(x,y,2)
    #     print(label,coef[0],'* X^2+',coef[1],'* X') 
    #     line_label = r"${} x^2$".format(np.round(coef[0],6))
    #     ax2.plot(x,coef[0]*x**2+coef[1]*x,ls='--',label=line_label)  


x_lim = 5000
y_lim = 1000
# ax1.set_aspect(x_lim/y_lim)
# ax2.set_aspect(x_lim/y_lim)

# ax1.set_title('Plot lineal para algoritmos de ordenamiento')
ax1.set_ylabel('tiempo [ms]')
ax1.set_xlabel('n')
ax1.set_ylim(0,1000)
ax1.set_xlim(0,5000)

# ax2.set_title(r'Ajuste cuadrático para algoritmos $O(n^2)$')
# ax2.set_ylabel('tiempo [ms]')
# ax2.set_xlabel('n')


ax1.legend(loc="best")
# ax2.legend(loc="best")

for file in data:
    df = pd.read_csv(file)
    label = file.split('_')[0]
    x = df['n'].values
    y = df['time[ms]'].values
    ax2.plot(x, y, label=label)

ax2.set_ylabel('tiempo [ms]')
ax2.set_xlabel('n')
ax2.set_ylim(0,25)
ax2.set_xlim(0,1000)
ax2.legend()
plt.show()

