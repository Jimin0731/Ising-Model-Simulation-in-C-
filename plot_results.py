import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv("~/Downloads/Programming CW/results.csv")

plt.figure()
plt.plot(df["beta"], df["avg_energy"], marker='o')
plt.title("Average Energy vs Beta")
plt.xlabel("Beta (1/kT)")
plt.ylabel("Average Energy")
plt.grid(True)
plt.savefig("energy_vs_beta.png")

plt.figure()
plt.plot(df["beta"], df["avg_magnetization"], marker='o', color='orange')
plt.title("Average Magnetization vs Beta")
plt.xlabel("Beta (1/kT)")
plt.ylabel("Average Magnetization")
plt.grid(True)
plt.savefig("magnetization_vs_beta.png")

plt.show()
