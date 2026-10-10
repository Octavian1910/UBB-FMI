from random import sample
from math import perm, comb
from itertools import permutations, combinations

def aranjamente(word,k,numar_total=False,aleator=False):
    if aleator==True:
        return sample(word,k)
    elif numar_total:
        return perm(len(word),k)
    else:
        return list(permutations(word,k))

def combinari(word,k,numar_total=False,aleator=False):
    if aleator==True:
        return sample(word,k)
    elif numar_total:
        return comb(len(word),k)
    else:
        return list(combinations(word,k))

print(aranjamente('word',2,aleator=True))
print(aranjamente('word', 2))
print(aranjamente('word', 2, numar_total=True))


print(combinari('word',2,aleator=True))
print(combinari('word', 2))
print(combinari('word', 2, numar_total=True))






