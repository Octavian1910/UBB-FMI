from math import comb

# prob sa alegem cel putin o bila rosie
#facem 1 - prob sa alegem o bila care nu e rosie
PA = 1 - comb(5, 3) / comb(10, 3)

#probabilitatea ca toate cele 3 bile sa fie rosii
PAB = comb(5, 3) / comb(10, 3)

# Calculam probabilitatea conditionata P(B|A):
P = PAB / PA

# Afisam probabilitatea teoretica obtinuta
print(P)