import matplotlib.pyplot as plt
import pandas as pd


testCases = 1000
file = open("time_computations.txt", "r")


file.readline()
heap_sort = list(file.readline().split(" "))
del heap_sort[-1]
heap_sort = [int(x) for x in heap_sort]

df = pd.DataFrame({'y': heap_sort})
rolling_mean = df.rolling(window=10).mean()
heapSort_smooth = rolling_mean['y'].values


file.readline()
heap_sort_variant = list(file.readline().split(" "))
del heap_sort_variant[-1]
heap_sort_variant = [int(x) for x in heap_sort_variant]

df = pd.DataFrame({'y': heap_sort_variant})
rolling_mean = df.rolling(window=10).mean()
heapSortVariant_smooth = rolling_mean['y'].values

file.close()

plt.plot(range(testCases), heapSort_smooth, label="Heap Sort", linewidth=2)
plt.plot(range(testCases), heapSortVariant_smooth, label="Heap Sort Variant", linewidth=2)

plt.xlabel("Size of Vector")
plt.ylabel("Time in Microseconds")
plt.title("Compuation Time")
plt.show()
