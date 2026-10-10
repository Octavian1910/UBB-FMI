import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation

# vectorii bazei
e1 = np.array([1, 0])   # vector initial
e2 = np.array([0, 1])   # tinta (sens pozitiv)

fig, ax = plt.subplots()
ax.set_xlim(-1.5, 1.5)
ax.set_ylim(-1.5, 1.5)
ax.set_aspect('equal')
ax.grid()

# sageata animata
arrow = ax.quiver(0, 0, e1[0], e1[1], angles='xy',
                  scale_units='xy', scale=1, color='blue')

# vectorul final
ax.quiver(0, 0, e2[0], e2[1], angles='xy',
          scale_units='xy', scale=1, color='red')

ax.set_title("Rotatia lui e1 spre e2 (sens trigonometric pozitiv)")

def update(frame):
    angle = frame * np.pi / 90   # rotatie progresiva
    rot = np.array([
        [np.cos(angle), -np.sin(angle)],
        [np.sin(angle),  np.cos(angle)]
    ])

    v = rot @ e1
    arrow.set_UVC(v[0], v[1])
    return arrow,

ani = FuncAnimation(fig, update, frames=180, interval=30)

plt.show()