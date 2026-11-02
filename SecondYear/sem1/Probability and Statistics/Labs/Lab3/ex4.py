from random import randrange, sample

#a
print('a)')
v = list(range(1, 101))
k = randrange(1, 101)

w = sample(v, k) # alegem k elemente din v fara returnare

rezultat = max(w) # calculam maximul sublistei w

print("k =", k) # afisam valoarea lui k

print("w =", w) # afisam sublista obtinuta

print("Maximul =", rezultat) # afisam rezultatul algoritmului

#b
print('b)')
from random import randrange, sample

v = list(range(1, 101))

nr_sim = 10000

count = 0 # contor egale cu 100

for _ in range(nr_sim):

    k = randrange(1, 101) # alegem aleator numarul k intre 1 si 100

    w = sample(v, k) # alegem k elemente din v fara returnare

    rezultat = max(w) # calculam maximul sublistei w

    if rezultat == 100: # verificam daca maximul este 100
        count += 1

P_estimat = count / nr_sim

print("Numar rezultate egale cu 100:", count)

print("Probabilitatea estimata:", P_estimat)



#c
print('c)')
suma_k = sum(range(1, 101))

# calculam probabilitatea teoretica
P_teoretic = suma_k / (100 * 100)

# afisam probabilitatea teoretica
print("Probabilitatea teoretica:", P_teoretic)