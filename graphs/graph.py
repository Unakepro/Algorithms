import matplotlib.pyplot as plt
import numpy as np

array_sizes = [n for n in range(1, 1001)]

data = []

with open('data.txt', 'r') as file:
	for line in file.readlines():
			if(line):
				data.append(float(line))


x = np.array(array_sizes)
y = np.array(data)

plt.figure(figsize=(25, 20))

plt.plot(x, y[0:1000], color = 'red', label = 'quicksort')
plt.plot(x, y[1000:2000], color = 'green', label = 'heapsort')
plt.plot(x,	y[2000:3000], color = 'blue', label = 'radixsort')


plt.xlabel("size of array")
plt.ylabel("time taken")

plt.legend()
plt.show()
