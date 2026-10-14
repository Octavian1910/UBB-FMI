from matplotlib.pyplot import axis, plot, show
from random import random
from math import dist

axis('square')
axis((0, 1, 0, 1))

A, B, C, D, E = [0, 0], [1, 0], [1, 1], [0, 1], [0.5, 0.5]

nrpuncte = 2000
cerinta = int(input("Introduceti cerinta (1-4): "))

nr_puncte_bune = 0

match cerinta:
    case 1:
        for i in range(nrpuncte):
            F = [random(), random()]

            if dist(E, F) < 0.5:
                nr_puncte_bune += 1
                plot(F[0], F[1], 'ro')
            else:
                plot(F[0], F[1], 'bo')

        frecventa = nr_puncte_bune / nrpuncte
        print("Frecventa relativa:", frecventa)
        print("Probabilitatea teoretica:", 3.14159 / 4)
        show()

    case 2:
        for i in range(nrpuncte):
            F = [random(), random()]

            if dist(E, F) < min(dist(A, F), dist(B, F),
                                dist(C, F), dist(D, F)):
                nr_puncte_bune += 1
                plot(F[0], F[1], 'ro')
            else:
                plot(F[0], F[1], 'bo')

        frecventa = nr_puncte_bune / nrpuncte
        print("Frecventa relativa:", frecventa)
        print("Probabilitatea teoretica:", 0.5)
        show()

    case 3:
        for i in range(nrpuncte):
            F = [random(), random()]

            if dist(E, F) < F[1]:
                nr_puncte_bune += 1
                plot(F[0], F[1], 'ro')
            else:
                plot(F[0], F[1], 'bo')

        frecventa = nr_puncte_bune / nrpuncte
        print("Frecventa relativa:", frecventa)
        print("Probabilitatea teoretica:", 2 / 3)

        show()

    case 4:
        for i in range(nrpuncte):
            F = [random(), random()]

            obtuz = 0

            if dist(F, A) ** 2 + dist(F, B) ** 2 < 1:
                obtuz += 1

            if dist(F, B) ** 2 + dist(F, C) ** 2 < 1:
                obtuz += 1

            if dist(F, C) ** 2 + dist(F, D) ** 2 < 1:
                obtuz += 1

            if dist(F, D) ** 2 + dist(F, A) ** 2 < 1:
                obtuz += 1

            if obtuz == 2:
                nr_puncte_bune += 1
                plot(F[0], F[1], 'ro')
            else:
                plot(F[0], F[1], 'bo')

        frecventa = nr_puncte_bune / nrpuncte
        print("Frecventa relativa:", frecventa)
        print("Probabilitatea teoretica:", 3.14159 / 2 - 1)
        show()
