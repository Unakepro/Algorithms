import matplotlib.pyplot as plt
import numpy as np


array_sizes = []

hybrid_time = []


data = []

with open('hybrid_data.txt', 'r') as file:
	for count, line in enumerate(file.readlines()):
			if(count > 0):
				array_sizes.append(float(line.split(" ")[0]))
				hybrid_time.append(float(line.split(" ")[1].replace('\n', '')))


x = np.array(array_sizes)

y_h = np.array(hybrid_time)


plt.figure(figsize=(25, 20))

plt.plot(x, y_h, color = 'black', label = 'hybridsort')

plt.xlabel("size of array")
plt.ylabel("time taken")

plt.legend()
plt.savefig('hybrid_sorted.png')

plt.show()
