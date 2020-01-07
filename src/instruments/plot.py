from matplotlib import pyplot as plt 
import numpy as np 

def read_txt(filename):
    txt = open(filename, 'r')
    txt = txt.readlines()
    txt.pop(0)
    values = []
    for line in txt:
        values.append(float(line))
    return np.array(values)


filename1 = "../../work/tblfile.txt"
filename = "../../work/xvector.txt"
x = read_txt(filename)
tbl = read_txt(filename1)
plt.plot(x[0:2500], 'b.', markersize=12)
plt.plot(tbl[0:2500], 'r-')
plt.title("Vector generat recorrent tbl")
plt.legend(["Mostres", "Tbl Original"], loc='upper right')
plt.autoscale(enable=True, axis='x', tight=True)
plt.show()
