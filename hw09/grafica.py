import matplotlib.pyplot as plt
import numpy as np

#import data into array "data"
data = np.loadtxt("datos.txt")

#Save data in columns
t = data[:,0]
y = data[:,1]
v = data[:,2]

#figure construction
fig1 = plt.figure( figsize=(5,10))

#t vs y
ax1 = fig1.add_subplot(211)
ax1.scatter(t, y, s = 2)
ax1.title.set_text('Time vs Height')
ax1.set_xlabel('Time (s)')
ax1.set_ylabel('Heigth (m)')

#t vs v
ax2 = fig1.add_subplot(212)
ax2.scatter(t,v, s = 2)
ax2.title.set_text('Time vs Speed')
ax2.set_xlabel('Time (s)')
ax2.set_ylabel('Speed (m/s)')

#avoid overlapping
plt.tight_layout()

#saving
plt.savefig('grafico.pdf')