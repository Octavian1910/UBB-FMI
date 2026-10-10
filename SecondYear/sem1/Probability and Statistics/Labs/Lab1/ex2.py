import random
from random import sample
from math import factorial
from itertools import permutations

list_permutations = list(permutations('randomise'))
print(list_permutations)

print(factorial(len('randomise')))

print(sample('randomise',len('randomise')))

