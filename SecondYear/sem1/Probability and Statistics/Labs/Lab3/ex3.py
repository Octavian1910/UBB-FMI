from scipy.stats import binom
from matplotlib.pyplot import bar, hist, grid, show, legend
#nr extrageri
print('a)')
n = 5

# nr total bile din urna
nr_bile = 10

# nr de bile cu cifra 1
nr_bile_1 = 6

# prob de a extrage o bila cu cifra 1
p = nr_bile_1 / nr_bile

# nr de valori pe care le generam
nr_sim = 1000

X = binom.rvs(n, p, size=nr_sim)

print(X)

#b
print('b)')
# Stabilim marginile intervalelor pentru valorile posibile 0, 1, 2, 3, 4, 5
bin_edges = [k - 0.5 for k in range(n + 2)]

hist(X, bin_edges, density=True, rwidth=0.9, color='green',
     edgecolor='black', alpha=0.5, label='frecvente relative')

# calc prob teoretica pt fiecar eval a lui X
distribution = dict([(i, binom.pmf(i, n, p)) for i in range(n + 1)])

bar(list(distribution.keys()), list(distribution.values()), width=0.85,
    color='red', edgecolor='black', alpha=0.6, label='probabilitati')

legend(loc='upper right')

grid()

show()


#c
print('c)')
P_estimat = sum(2 < x <= 5 for x in X) / nr_sim

P_X_mai_mic_egal_5 = binom.cdf(5, n, p)

P_X_mai_mic_egal_2 = binom.cdf(2, n, p)

P_teoretic = P_X_mai_mic_egal_5 - P_X_mai_mic_egal_2

print("Probabilitatea estimata:", P_estimat)

print("Probabilitatea teoretica:", P_teoretic)