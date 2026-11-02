from random import randrange

from matplotlib.pyplot import bar, hist, grid, show, legend

data = [randrange(1, 7) for _ in range(500)]

bin_edges = [k + 0.5 for k in range(7)]

hist(data, bin_edges, density=True, rwidth=0.9, color='green',
     edgecolor='black', alpha=0.5, label='frecvente relative')

# Calculam probabilitatea teoretica pentru fiecare fata a zarului , fiecare rezultat are probabilitatea 1/6
distribution = dict([(i, 1/6) for i in range(1, 7)])

# desenam barele probabilitatilor teoretice
bar(list(distribution.keys()), list(distribution.values()), width=0.85,
    color='red', edgecolor='black', alpha=0.6, label='probabilitati')

# afisam legenda graficului
legend(loc='lower left')

# afisam grila pentru a putea compara mai usor valorile
grid()

# afisam graficul final
show()