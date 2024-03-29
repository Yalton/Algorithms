



from mpl_toolkits import mplot3d
import numpy as np
import matplotlib.pyplot as plt
# triangulate in the underlying parametrization
from matplotlib.tri import Triangulation


fig = plt.figure()
ax = plt.axes(projection='3d')

theta = np.linspace(0, 2 * np.pi, 30)
w = np.linspace(-0.25, 0.25, 8)
w, theta = np.meshgrid(w, theta)

phi = 0.5 * theta


# radius in x-y plane
r = 1 + w * np.cos(phi)

x = np.ravel(r * np.cos(theta))
y = np.ravel(r * np.sin(theta))
z = np.ravel(w * np.sin(phi))

tri = Triangulation(np.ravel(w), np.ravel(theta))


ax.plot_trisurf(x, y, z, triangles=tri.triangles,
                cmap='viridis', linewidths=0.2)

ax.set_xlim(-1, 1); ax.set_ylim(-1, 1); ax.set_zlim(-1, 1)


ax.set_xlabel('x')
ax.set_ylabel('y')
ax.set_zlabel('z')
ax.set_title('mobius')

# Set the view of the 3D viewer
ax.view_init(60, 35)

plt.show()