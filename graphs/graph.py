import matplotlib.pyplot as plt
import numpy as np

array_sizes = []

insertion_time = []
heapsort_time =  []
quicksort_time = []
radixsort_time = []


data = []

with open('data.txt', 'r') as file:
	for count, line in enumerate(file.readlines()):
			if(count > 0):
				array_sizes.append(float(line.split(" ")[0]))
				insertion_time.append(float(line.split(" ")[1]))
				heapsort_time.append(float(line.split(" ")[2]))
				quicksort_time.append(float(line.split(" ")[3]))
				radixsort_time.append(float(line.split(" ")[4].replace('\n', '')))


x = np.array(array_sizes)

y_i = np.array(insertion_time)
y_h = np.array(heapsort_time) 
y_q = np.array(quicksort_time)
y_r = np.array(radixsort_time)


plt.figure(figsize=(25, 20))

plt.plot(x, y_i, color = 'c', label = 'insertion_sort')
plt.plot(x, y_q, color = 'red', label = 'quicksort')
plt.plot(x, y_h, color = 'green', label = 'heapsort')
plt.plot(x,	y_r, color = 'blue', label = 'radixsort')

plt.xlabel("size of array")
plt.ylabel("time taken")

plt.legend()
plt.savefig('sorted.png')

plt.show()
