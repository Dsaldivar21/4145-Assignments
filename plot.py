import pandas as pd
import matplotlib.pyplot as plt

data = [
    ("Sorted 10 elements", 3.24e-06),
    ("Sorted 100 elements", 3.0458e-05),
    ("Sorted 1000 elements", 0.000350368),
    ("Sorted 10000 elements", 0.00416242),
    ("Sorted 100000 elements", 0.0485208),
    ("Sorted 1000000 elements", 0.542528),
    ("Sorted 10000000 elements", 6.08743),
    ("Sorted 100000000 elements", 67.3788),
    ("Sorted 1000000000 elements", 740.605)
]

df = pd.DataFrame(data, columns=["Description", "Time"])

df["Elements"] = df["Description"].apply(lambda x: int(x.split()[1]))

plt.plot(df["Elements"], df["Time"], marker="o", linestyle="-", color="b", label="Sort Time")

plt.xlabel("Number of Elements")
plt.ylabel("Time (Seconds)")
plt.title("Sorting Time vs Number of Elements")
plt.xscale('log')
plt.yscale('log')
plt.legend()
plt.grid(True)

plt.savefig("sorting_time_vs_elements.png", format="png")

plt.show()
