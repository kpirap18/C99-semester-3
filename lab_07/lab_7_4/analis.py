import matplotlib.pyplot as plt
plt.xlabel("COUNT IN ARRAY")
plt.ylabel("TIME")
plt.grid(True)
plt.title("TIME(COUNT)")
y1 = (0, 0, 9, 19, 19, 19, 89, 59, 189, 79)
y2 = (0, 9, 19, 49, 39, 49, 518, 119, 329, 329)
x = (10, 110, 210, 310, 410, 510, 610, 710, 810, 910)
plt.plot(x, y1, '-',label ="mysort")
plt.plot(x, y2,'--', label="qsort")
plt.legend()
plt.show()
