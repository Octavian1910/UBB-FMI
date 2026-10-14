from itertools import product
from random import randint

from matplotlib.pyplot import bar, show, plot

sum_counts = {total: 0 for total in range(3, 19)}

for roll in product(range(1, 7), repeat=3):
    sum_counts[sum(roll)] += 1

plot(sum_counts.keys(), sum_counts.values(), 'ro')
show()


sum_counts = {total: 0 for total in range(3, 19)} #resetam
for i in range(100000):
    zar1 = randint(1, 6)
    zar2 = randint(1, 6)
    zar3 = randint(1, 6)

    total = zar1 + zar2 + zar3
    sum_counts[total] += 1

plot(sum_counts.keys(), sum_counts.values(), 'ro')
show()