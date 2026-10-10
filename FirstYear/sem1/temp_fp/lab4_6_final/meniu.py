from ui import *
from UI2 import *

def afisare_meniu():
    """
    Functia afiseaza meniul principal al aplicatiei
    """
    print("1) Adauga un scor la un participant")
    print("2) Modificare scor")
    print("3) Tipareste lista de participanti")
    print("4) Operatii pe un subset de participanti")
    print("5) Filtrare")
    print("6) Undo")
    print("7) Iesire")



def run():
    """
    Functia de UI
    Returns: -

    """
    concurenti = []
    istoric = []
    while True:
        afisare_meniu()
        optiune = input("Optiunea aleasa este : ")
        try :
            optiune = int(optiune)
            if optiune == 1:
                adauga_scor_la_un_participant(concurenti,istoric)
            if optiune == 2:
                modificare_scor(concurenti,istoric)
            if optiune == 3:
                tipareste_lista_de_participanti(concurenti)
            if optiune == 4:
                operatii_la_un_subset_de_participanti(concurenti)
            if optiune == 5:
                filtrare(concurenti,istoric)
            if optiune == 6 :
                undo_ui(concurenti,istoric)
            if optiune == 7:
                break
        except ValueError:
            optiune = optiune.lower()
            optiune = optiune.split(" ")
            if optiune[0] == 'adauga':
                try_adauga_scor_la_un_participant(concurenti, istoric)
            if optiune[0] == 'modificare':
                try_modificare_scor(concurenti, istoric)
            if optiune[0] == 'tipaste':
                try_tipareste_lista_de_participanti(concurenti)
            if optiune[0] == 'operatii':
                try_operatii_la_un_subset_de_participanti(concurenti)
            if optiune[0] == 'filtrare':
                try_filtrare(concurenti, istoric)
            if optiune[0] == 'undo':
                try_undo_ui(concurenti, istoric)
            if optiune == 'iesire':
                break


        afisare_concurenti(concurenti)
