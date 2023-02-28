import matplotlib.pyplot as plt
import numpy as np

#numpy array that holds random case time computations
random = np.array([0, 0, 1, 1, 2, 2, 3, 3, 3, 4, 
                   5, 6, 4, 4, 5, 5, 5, 6, 6, 7, 
                   10, 9, 10, 10, 11, 12, 12, 13, 
                   14, 19, 16, 27, 18, 19, 19, 20, 
                   22, 22, 24, 34, 26, 27, 29, 31, 
                   32, 33, 34, 40, 38, 37])

#numpy array that holds case A time computations
caseA = np.array([0, 0, 0, 0, 1, 1, 2, 3, 3, 3, 4, 
                  5, 6, 6, 7, 7, 8, 8, 9, 9, 8, 10, 
                  11, 12, 12, 13, 14, 15, 15, 17, 18, 
                  19, 20, 20, 21, 23, 23, 24, 47, 27,
                  43, 49, 50, 50, 54, 57, 61, 63, 66, 76])

#numpy array that holds case B time computations
caseB = np.array([0, 0, 0, 1, 1, 1, 2, 2, 3, 3, 
                  4, 5, 6, 6, 8, 8, 8, 10, 7, 12, 
                  14, 9, 9, 10, 36, 19, 13, 13, 19, 17, 
                  16, 16, 25, 39, 33, 21, 23, 33, 41, 34, 
                  29, 26, 28, 33, 32, 32, 33, 35, 37, 40])


#plot the three lines
plt.plot(random, label="Random")
plt.plot(caseA, label="Case A")
plt.plot(caseB, label="Case B")

#add some lables, a title, and a legend
plt.xlabel("Number of Elements")
plt.ylabel("Time in Microseconds")
plt.title("Compuation Time")
plt.legend()
plt.show()


