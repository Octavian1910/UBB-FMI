from service import *
from meniu import *

def try_adauga_scor_la_un_participant(concurenti, istoric):
    """
    Functia citeste optiunea utilizatorului
    Args:
        concurenti : o lista de participanti
        istoric : o lista cu valorile programului inainte de fiecare noua operatie

    Returns: -


    """
    while True :
        print("1) Adauga un nou participant")
        print("2) Insereaza scor pentru un participant existent")
        print("3) Iesire")
        optiune =  input("Alege(optiunea): ")
        optiune = optiune.lower()
        optiune = optiune.split()
        if optiune[0] == "adauga" :
            try_adaugare_concurent_ui(concurenti,istoric)
        elif optiune[0] == "insereaza":
            try_inserare_scor_concurent_ui(concurenti,istoric)
        elif optiune[0] == "iesire" :
            break
        else :
            print("Optiune invalida!")


def try_adaugare_concurent_ui(concurenti,istoric):
    """
    Functia primeste lista cu concurentii actuali si mai introduce inca un concurent
    Args:
        concurenti: o lista de concurenti
        istoric: o lista cu valorile programului inainte de fiecare noua operatie
    Returns:-
        Nu returneaza nimic dar daca concurentul are datele valide va fi afisat mesajul "Concurent adaugat cu succes!" in caz contrar un mesaj de eroare
    """
    actualizeaza_istoric(concurenti,istoric)
    date_introduse = input("Introdu ID,NUME si SCORURI ")
    date_introduse = date_introduse.split()
    id_concurent = int(date_introduse[0])
    nume_concurent = date_introduse[1]
    scoruri = date_introduse[2:]
    convertire_lista_string_la_float(scoruri)
    scor_final = calculare_scor_final(scoruri)
    concurent = creeare_concurent(id_concurent, nume_concurent, scoruri,scor_final)
    rezultat,mesaj = adaugare_concurent(concurenti, concurent)
    if rezultat:
        print("Concurent adaugat cu succes!")
    else :
        print(mesaj)
        istoric.pop()

def try_inserare_scor_concurent_ui(concurenti,istoric):
    """
    Functia primeste lista concurentilor , apoi insereaza scorul dorit la concurentul dorit
    Args:
        concurenti: o lista cu concurenti
        istoric : istoric: o lista cu valorile programului inainte de fiecare noua operatie
    Returns:
    """
    actualizeaza_istoric(concurenti,istoric)
    date_introduse = input("Introdu ID,NUMAR PROBA si SCORURUL pe care doriti sa l inserati ")
    date_introduse = date_introduse.split()
    id_concurent = int(date_introduse[0])
    numarul_probei = int(date_introduse[1])
    scor_de_inserat =  float(date_introduse[2])
    rezultat,mesaj = insereaza_scor_la_proba(concurenti, id_concurent, numarul_probei, scor_de_inserat)
    if rezultat:
        print("Scor inserat cu succes! ")
    else :
        print(mesaj)
        istoric.pop()



def  calculare_scor_final(scoruri) :
    """
    Primesate o lista de numere float scoruri si calculeaza suma tuturor elementelor din ea
    Args:
        scoruri: o lista cu nuemre de tip float

    Returns:
        Un numar de tio float reprezentand suma tuturor scorurilor
    """
    suma = 0.0
    for scor in scoruri:
        suma += scor
    return suma

def convertire_lista_string_la_float(scoruri):
    """
    Primeste o lista de inturi si o transforma in lista de floaturi
    Args:
        scoruri: un numar de tip float

    Returns:-

    """
    for i in range(len(scoruri)):
        scoruri[i] = float(scoruri[i])


def try_modificare_scor(concurenti, istoric):
    '''
    Functia citeste optiunea utilizatorului
    Args:
        concurenti: o lista cu concurenti
        istoric: o lista cu valorile programului inainte de fiecare noua operatie

    Returns:

    '''
    while True :
        print("1) Sterge scorul pentru un participant dat")
        print("2) Sterge scorul pentru un interval de participanti")
        print("3) Inlocuieste scorul de la un participant")
        print("4) Iesire")
        optiune = input()
        optiune = optiune.lower()

        if optiune == "sterge scorul pentru un participant dat":
            try_stergere_scor_pentru_concurent_ui(concurenti,istoric)
        elif optiune == "sterge scorul pentru un interval de participanti":
            try_sterge_scor_pentru_interval_de_concurenti_ui(concurenti,istoric)
        elif optiune == "inlocuieste scorul de la un participant":
            try_inlocuieste_scorul_de_la_un_concurent_ui(concurenti,istoric)
        elif optiune == 4:
            break
        else :
            print("Optiune invalida!")


def try_undo_tui(concurenti,istoric) :
    rezultat = undo(concurenti,istoric)
    if rezultat:
        print("S-a dat undo cu succes!")
    else:
        print("Nu s-a putut da undo!")


def try_stergere_scor_pentru_concurent_ui(concurenti,istoric):
    """
    Functia sterge scorul de la o anumita proba la concurentul dorit
    Args:
        concurenti:  o lista cu concurenti
        istoric : istoric: o lista cu valorile programului inainte de fiecare noua operatie

    Returns: -
    """
    actualizeaza_istoric(concurenti,istoric)
    print("ID si numarul probei unde doriti sa stergeti :")
    date_introduse = input()
    date_introduse = date_introduse.split()
    id_concurent = int(date_introduse[0])
    numarul_probei = int(date_introduse[1])
    rezultat,mesaj = stergere_scor_pentru_concurent(concurenti, id_concurent, numarul_probei)
    if rezultat:
        print("Proba a fost stearsa cu succes!")
    else :
        print(mesaj)
        istoric.pop()


def try_sterge_scor_pentru_interval_de_concurenti_ui(concurenti, istoric):
    """
    Stergere scorul de la o anumita proba pentru un interval de concurenti
    Args:
        concurenti: o lista cu concurenti
        istoric : o lista cu valorile programului inainte de fiecare noua operatie
    Returns:-

    """
    actualizeaza_istoric(concurenti, istoric)
    print("Introduceti Start Interval , End Interval si Numarul Probei care doriti sa fie stearsa : ")
    date_introduse = input()
    start_interval = int(date_introduse[0])
    end_interval = int(date_introduse[1])
    numar_proba_care_trebuie_sa_fie_stearsa = int(date_introduse[2])
    rezultat, mesaj = sterge_scor_pentru_interval_de_concurenti(concurenti, start_interval, end_interval,
                                                                numar_proba_care_trebuie_sa_fie_stearsa)
    if rezultat:
        print("Proba a fost stearsa cu succes pe intervalul dorit!")
    else:
        print(mesaj)
        istoric.pop()

def try_inlocuieste_scorul_de_la_un_concurent_ui(concurenti,istoric) :
    """
    Functia inlocuieste scorul de la un concurent la proba dorita
    Args:
        concurenti: o lista cu concurenti
        istoric: o lista cu valorile programului inainte de fiecare noua operatie
    Returns:

    """
    actualizeaza_istoric(concurenti,istoric)
    print("ID si Numarul Probei si Scorul :")
    date_introduse = input()
    id_concurent = int(date_introduse[0])
    numar_proba_la_care_inlocuim = int(date_introduse[1])
    scor_nou = float(date_introduse[2])
    rezultat, mesaj = inlocuieste_scorul_de_la_un_concurent(concurenti, id_concurent, numar_proba_la_care_inlocuim,scor_nou)
    if rezultat:
        print("Scorul a fost inlocuit cu succes!")
    else:
        print(mesaj)
        istoric.pop()

def try_tipareste_lista_de_participanti(concurenti):
    """
    Functia citeste optiunea utilizatorului
    Args:
        concurenti: o lista cu concurenti

    Returns:

    """
    while True :
        print("1) Participanti cu scor mai mic decat o valoare data")
        print("2) Participanti ordonati dupa scor")
        print("3) Participanti cu scor mai mare decat un scor dat ordonati")
        print("4) Iesire")
        optiune = input()
        optiune = optiune.lower()
        if optiune == "participanti cu scor mai mic decat o valoare data":
            try_tipareste_scor_mai_mic_decat_cel_dat_ui(concurenti)
        elif optiune == "participanti ordonati dupa scor":
            try_tipareste_ordonat_dupa_scor_ui(concurenti)
        elif optiune == "participanti cu scor mai mare decat un scor dat ordonati":
            try_tipareste_concurentii_cu_scor_mai_mare_decat_scorul_dat_ordonati_ui(concurenti)
        elif optiune == "iesire" :
            break
        else:
            print("Optiune invalida!")


def try_tipareste_scor_mai_mic_decat_cel_dat_ui(concurenti):
    """
    Citeste un scor si returneaza toti participantii care au scorul mai mic decat scorul final
    Args:
        concurenti: un concurent din lista concurenti

    Returns: -

    """
    scor_de_comparat = int(input("Tipareste participantii care au scorul mai mic decat : "))
    lista_de_afisat,mesaj = concurentii_scor_mai_mic_decat_cel_dat(concurenti,scor_de_comparat)
    if len(mesaj) != 0:
        print(mesaj)
    else : afisare_concurenti(lista_de_afisat)

def try_tipareste_ordonat_dupa_scor_ui(concurenti):
    """
    Functia tipareste concurentii ordonati dupa scor
    Args:
        concurenti: o lista cu concurenti

    Returns:-
    """
    print("1)Crescator \n 2)Descrescator ")
    date_introduse = input()
    date_introduse.lower()
    if date_introduse == "crescator" :
        optiune = 1
    else :
        optiune = 2
    lista_de_afisat,mesaj = tipareste_ordonat_dupa_scor(concurenti,optiune)
    if lista_de_afisat :
        afisare_concurenti(lista_de_afisat)
    else :
        print(mesaj)