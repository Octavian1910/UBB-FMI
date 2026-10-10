from random import sample
from math import perm, comb
from itertools import permutations, combinations
from itertools import combinations_with_replacement

lista=["A", "C", "F", "K", "M","V", "Z"]

response=list(combinations_with_replacement(lista,3));

print(response);
print(comb(len(lista)+3-1,3));
