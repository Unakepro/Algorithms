import matplotlib.pyplot as plt
import numpy as np

array_sizes = []
data = []

with open('data.txt', 'r') as file:
	for count, line in enumerate(file.readlines()):
		if count % 2 == 0:
			array_sizes.append(float(line))
		else:
			data.append(float(line))

x = np.array(array_sizes)
y = np.array(data)

print(x)
print(y)


plt.figure(figsize=(25, 20))
plt.plot(x, y)

plt.xlabel("size of array")
plt.ylabel("time taken")

plt.show()
