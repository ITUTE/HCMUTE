import numpy as np
import matplotlib.pyplot as plt

x = np.arange(-5,5,0.1)
y1 = 2*x**2 - 3*x + 5
y2 = x**3 - 2*x**2 + 3*x - 4

plt.plot(x,y1,color='red')
plt.plot(x,y2,color='blue')

plt.title("Biểu đồ hàm số")
plt.legend(["y1 = 2*x^2 - 3*x + 5", "y2 = x^3 - 2*x^2 + 3*x - 4"])
plt.xlabel("x")
plt.ylabel("y")
plt.grid()
plt.show()
