import matplotlib
import matplotlib.pyplot as plt
import numpy as np

# Función tomada del siguiente sitio:
# https://facialix.com/tutorial-creacion-de-graficas-en-python-usando-matplotlib/
def autolabel(rects):
    """Funcion para agregar una etiqueta con el valor en cada barra"""
    for rect in rects:
        height = rect.get_height()
        ax.annotate('{}'.format(round(height,2)),
                    xy=(rect.get_x() + rect.get_width() / 2, height),
                    xytext=(0, 3),  # 3 points vertical offset
                    textcoords="offset points",
                    ha='center', va='bottom')

percents = [20, 50, 80]
sizes = [10, 100, 10000]
indices = [1, 361]
doms = [0, 1]

measures = open("../data/measurements/a.txt")


cnt20_0 = [0]*3
cnt20_1 = [0]*3
cnt50_0 = [0]*3
cnt50_1 = [0]*3
cnt80_0 = [0]*3
cnt80_1 = [0]*3
avgTime20_0 = [0]*3
avgTime20_1 = [0]*3
avgTime50_0 = [0]*3
avgTime50_1 = [0]*3
avgTime80_0 = [0]*3
avgTime80_1 = [0]*3
for j in range(indices[0], indices[1]):
    line = measures.readline().strip().split()
    modes = line[0].strip(".dat").split("_")
    sizeMode = sizes.index(int(modes[0]))
    type = modes[1]
    d = modes[2]
    eTime = float(line[2])
    if d == "0":
        if type == '20':
            cnt20_0[sizeMode] += 1
            avgTime20_0[sizeMode] += eTime
        elif type == '50':
            cnt50_0[sizeMode] += 1
            avgTime50_0[sizeMode] += eTime
        else:
            cnt80_0[sizeMode] += 1
            avgTime80_0[sizeMode] += eTime
    else:
        if type == '20':
            cnt20_1[sizeMode] += 1
            avgTime20_1[sizeMode] += eTime
        elif type == '50':
            cnt50_1[sizeMode] += 1
            avgTime50_1[sizeMode] += eTime
        else:
            cnt80_1[sizeMode] += 1
            avgTime80_1[sizeMode] += eTime
for j in range(3):
    if (cnt20_0[j] != 0):
        avgTime20_0[j] /= cnt20_0[j]
    if (cnt50_0[j] != 0):
        avgTime50_0[j] /= cnt50_0[j]
    if (cnt80_0[j] != 0):
        avgTime80_0[j] /= cnt80_0[j]
    if (cnt20_1[j] != 0):
        avgTime20_1[j] /= cnt20_1[j]
    if (cnt50_1[j] != 0):
        avgTime50_1[j] /= cnt50_1[j]
    if (cnt80_1[j] != 0):
        avgTime80_1[j] /= cnt80_1[j]
    
  # El siguiente código es mayormente tomado del sitio
  # https://facialix.com/tutorial-creacion-de-graficas-en-python-usando-matplotlib/

x = np.arange(len(sizes))
width = 0.2
  
for j in range(2):
    fig, ax = plt.subplots()
    if j==0:
      toUseA = avgTime20_0
      toUseD = avgTime50_0
      toUseR = avgTime80_0
    else:
      toUseA = avgTime20_1
      toUseD = avgTime50_1
      toUseR = avgTime80_1
    rectsAsc = ax.bar(x - width, toUseA, width, label='20% cambios')
    rectsDes = ax.bar(x,         toUseD, width, label='50% cambios')
    rectsRnd = ax.bar(x + width, toUseR, width, label='80% cambios')

    ax.set_ylabel('Tiempo de ejecución (s)')
    ax.set_title('Tiempo de ejecución de DP en tipo '+str(doms[j]))
    ax.set_xticks(x)
    ax.set_xticklabels(sizes)
    ax.legend()

    autolabel(rectsAsc)
    autolabel(rectsDes)
    autolabel(rectsRnd)
    fig.tight_layout()

    plt.savefig('../data/plots/'+str(doms[j])+'.png')

measures.close()
