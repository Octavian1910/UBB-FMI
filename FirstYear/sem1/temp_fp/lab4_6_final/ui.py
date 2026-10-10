from service import *


def adauga_scor_la_un_participant(concurenti,istoric):
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
        optiune = int(input("Alege optiunea: "))
        if optiune == 1:
            adaugare_concurent_ui(concurenti,istoric)
        elif optiune == 2:
            inserare_scor_concurent_ui(concurenti,istoric)
        elif optiune == 3:
            break
        else :
            print("Optiune invalida!")


def modificare_scor(concurenti,istoric):
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
        optiune = int(input("Alege optiunea: "))

        if optiune == 1:
            stergere_scor_pentru_concurent_ui(concurenti,istoric)
        elif optiune == 2:
            sterge_scor_pentru_interval_de_concurenti_ui(concurenti,istoric)
        elif optiune == 3:
            inlocuieste_scorul_de_la_un_concurent_ui(concurenti,istoric)
        elif optiune == 4:
            break
        else :
            print("Optiune invalida!")


def tipareste_lista_de_participanti(concurenti):
    """
    Functia citeste optiunea utilizatorului
    Args:
        concurenti: o lista cu concurenti

    Returns:

    """
    while True :
        print("1) Participanti cu scor mai mic decat o valoare data")
        print("2) Participanti ordonati dupa scor")
        print("3) Participanti cu scor mai mare decat un scor dat, ordonati")
        print("4) Iesire")
        optiune = int(input("Alege optiunea: "))
        if optiune == 1:
            tipareste_scor_mai_mic_decat_cel_dat_ui(concurenti)
        elif optiune == 2:
            tipareste_ordonat_dupa_scor_ui(concurenti)
        elif optiune == 3:
            tipareste_concurentii_cu_scor_mai_mare_decat_scorul_dat_ordonati_ui(concurenti)
        elif optiune == 4 :
            break
        else:
            print("Optiune invalida!")


def operatii_la_un_subset_de_participanti(concurenti):
    while True :
        print("1) Calculeaza media scorurilor pentru un interval dat")
        print("2) Calculeaza scorul minim pentru un interval dat")
        print("3) Tipareste participantii care au scor multiplu de 10")
        print("4) Iesire")
        optiune = int(input("Alege optiunea: "))
        if optiune == 1:
            calculeaza_media_scorurilor_interval_dat_ui(concurenti)
        elif optiune == 2:
            calculeaza_scor_minim_interval_participanti_ui(concurenti)
        elif optiune == 3:
            tipareste_concurentii_care_au_scorul_multiplu_de_zece_ui(concurenti)
        elif optiune == 4:
            break
        else:
            print("Optiune invalida!")



def filtrare(concurenti,istoric):
    while True :
        print("1) Filtrare participanti cu scor multiplu de un numar dat")
        print("2) Filtrare participanti cu scor mai mic decat un numar dat")
        print("3) Iesire")
        optiune = int(input("Alege optiunea: "))
        if optiune == 1:
            filtrare_concurenti_care_au_scorul_multiplu_de_numar_dat_ui(concurenti,istoric)
        elif optiune == 2:
            filtrare_concurenti_care_au_scorul_mai_mic_decat_un_numar_dat_ui(concurenti,istoric)
        elif optiune == 3:
            break
        else:
            print("Optiune invalida!")


def undo_ui(concurenti,istoric) :
    rezultat = undo(concurenti,istoric)
    if rezultat:
        print("S-a dat undo cu succes!")
    else:
        print("Nu s-a putut da undo!")





def adaugare_concurent_ui(concurenti,istoric):
    """
    Functia primeste lista cu concurentii actuali si mai introduce inca un concurent
    Args:
        concurenti: o lista de concurenti
        istoric: o lista cu valorile programului inainte de fiecare noua operatie
    Returns:-
        Nu returneaza nimic dar daca concurentul are datele valide va fi afisat mesajul "Concurent adaugat cu succes!" in caz contrar un mesaj de eroare
    """
    actualizeaza_istoric(concurenti,istoric)
    id_concurent = int(input("Id-ul concurentului "))
    nume_concurent = input("Nume-ul concurentului ")
    scoruri = input("Scorurile concurentului ")
    scoruri,scor_final = convertire_string_la_float_si_punere_in_lista(scoruri)
    concurent = creeare_concurent(id_concurent, nume_concurent, scoruri,scor_final)
    rezultat,mesaj = adaugare_concurent(concurenti, concurent)
    if rezultat:
        print("Concurent adaugat cu succes!")
    else :
        print(mesaj)
        istoric.pop()






def inserare_scor_concurent_ui(concurenti,istoric):
    """
    Functia primeste lista concurentilor , apoi insereaza scorul dorit la concurentul dorit
    Args:
        concurenti: o lista cu concurenti
        istoric : istoric: o lista cu valorile programului inainte de fiecare noua operatie
    Returns:
    """
    actualizeaza_istoric(concurenti,istoric)
    id_concurent = int(input("Id-ul concurentului unde doriti sa inserati scorul la inca o proba "))
    numarul_probei = int(input("La ce proba doresti sa inserezi numarul "))
    scor_de_inserat =  float(input("Scorul pe care doriti sa l inserati este "))
    rezultat,mesaj = insereaza_scor_la_proba(concurenti, id_concurent, numarul_probei, scor_de_inserat)
    if rezultat:
        print("Scor inserat cu succes!")
    else :
        print(mesaj)
        istoric.pop()


def stergere_scor_pentru_concurent_ui(concurenti,istoric):
    """
    Functia sterge scorul de la o anumita proba la concurentul dorit
    Args:
        concurenti:  o lista cu concurenti
        istoric : istoric: o lista cu valorile programului inainte de fiecare noua operatie

    Returns: -
    """
    actualizeaza_istoric(concurenti,istoric)
    id_concurent = int(input("Id-ul concurentului: "))
    numarul_probei = int(input("Ce proba doresti sa stergi: "))
    rezultat,mesaj = stergere_scor_pentru_concurent(concurenti, id_concurent, numarul_probei)
    if rezultat:
        print("Proba a fost stearsa cu succes!")
    else :
        print(mesaj)
        istoric.pop()

def sterge_scor_pentru_interval_de_concurenti_ui(concurenti,istoric) :
    """
    Stergere scorul de la o anumita proba pentru un interval de concurenti
    Args:
        concurenti: o lista cu concurenti
        istoric : o lista cu valorile programului inainte de fiecare noua operatie
    Returns:-
    
    """
    actualizeaza_istoric(concurenti,istoric)
    start_interval= int(input("Start interval de concurenti: "))
    end_interval= int(input("End interval de concurenti: "))
    numar_proba_care_trebuie_sa_fie_stearsa = int(input("Proba care trebuie_sa_fie_stearsa: "))
    rezultat,mesaj = sterge_scor_pentru_interval_de_concurenti(concurenti, start_interval, end_interval,numar_proba_care_trebuie_sa_fie_stearsa)
    if rezultat:
        print("Proba a fost stearsa cu succes pe intervalul dorit!")
    else :
        print(mesaj)
        istoric.pop()

def inlocuieste_scorul_de_la_un_concurent_ui(concurenti,istoric) :
    """
    Functia inlocuieste scorul de la un concurent la proba dorita
    Args:
        concurenti: o lista cu concurenti
        istoric: o lista cu valorile programului inainte de fiecare noua operatie
    Returns: 

    """
    actualizeaza_istoric(concurenti,istoric)
    id_concurent = int(input("Id-ul concurentului: "))
    numar_proba_la_care_inlocuim = int(input("La ce proba inlocuim: "))
    scor_nou = float(input("Scor_nou: "))
    rezultat, mesaj = inlocuieste_scorul_de_la_un_concurent(concurenti, id_concurent, numar_proba_la_care_inlocuim,scor_nou)
    if rezultat:
        print("Scorul a fost inlocuit cu succes!")
    else:
        print(mesaj)
        istoric.pop()


def tipareste_scor_mai_mic_decat_cel_dat_ui(concurenti):
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



def tipareste_ordonat_dupa_scor_ui(concurenti):
    """
    Functia tipareste concurentii ordonati dupa scor
    Args:
        concurenti: o lista cu concurenti

    Returns:-
    """
    optiune = int(input("1)Crescator 2)Descrescator "))
    lista_de_afisat,mesaj = tipareste_ordonat_dupa_scor(concurenti,optiune)
    if lista_de_afisat :
        afisare_concurenti(lista_de_afisat)
    else :
        print(mesaj)

def tipareste_concurentii_cu_scor_mai_mare_decat_scorul_dat_ordonati_ui(concurenti):
    """
    Functia afiseaza concurentii in ordine crescatoare / descrescatoare care au scorul mai mare decat scorul dorit
    Args:
        concurenti: o lista de concurenti

    Returns: -
    """
    optiune = int(input("1)Crescator 2)Descrescator "))
    scor = int(input("Scorul de reper este : "))
    lista_de_afisat,mesaj = ordoneaza_concurentii_cu_scor_mai_mare_decat_scorul_dat(concurenti,optiune,scor)
    if len(mesaj) == 0 :
        afisare_concurenti(lista_de_afisat)
    else :
        print(mesaj)



def calculeaza_media_scorurilor_interval_dat_ui(concurenti):
    """
    Functia calculeaza media scorurilor concurentiilor pe un interval dat
    Args:
        concurenti: o lista cu concurenti

    Returns: -
    """
    primul_concurent = int(input("Introduceti numarul din lista corespunzator concurentului de unde doriti sa incepeti :"))
    ultimul_concurent = int(input("Introduceti numarul din lista corespunzator concurentului  unde doriti sa terminati :"))
    functioneaza,valoare,mesaj = calculeaza_media_scorurilor_interval_dat(concurenti, primul_concurent, ultimul_concurent)
    if functioneaza:
        print(f"Media scorurilor este : {valoare}")
    else :
        print(mesaj)


def calculeaza_scor_minim_interval_participanti_ui(concurenti):
    """
    Functia afiseaza scorul minim final al concurentiilor din intervalul dorit
    Args:
        concurenti: o lista cu concurenti
    Returns:-
    """

    primul_concurent = int(input("Indexul primului concurent este :"))
    ultimul_concurent = int(input("Indexul ultimului concurent este :"))
    functioneaza, rezultat, mesaj = calcuealza_scor_minim_interval_participanti(concurenti, primul_concurent, ultimul_concurent)
    if functioneaza:
        print(f"Scorul minim este : {rezultat}")
    else :
        print(mesaj)


def tipareste_concurentii_care_au_scorul_multiplu_de_zece_ui(concurenti):
    """
    Functia afiseaza o lista cu concurentii care au scorul final multiplu de 10
    Returns:

    """
    lista_noua, mesaj = tipareste_concurentii_care_au_scorul_multiplu_de_numar(concurenti, 10)
    if not lista_noua:
        print(mesaj)
    else :
        print("Concurentii care au scorul multiplu de 10 sunt : ")
        afisare_concurenti(lista_noua)

def filtrare_concurenti_care_au_scorul_multiplu_de_numar_dat_ui(concurenti,istoric):
    """

    Args:
        concurenti:
        istoric: o lista cu valorile programului inainte de fiecare noua operatie

    Returns:

    """
    actualizeaza_istoric(concurenti,istoric)
    numar_multiplu = int(input("O sa ramana doar concurentii care au scorul multiplu de  : "))
    concurenti, mesaj = tipareste_concurentii_care_au_scorul_multiplu_de_numar(concurenti, numar_multiplu)
    if len(mesaj) > 0:
        istoric.pop()
        print(mesaj)
    else :
        print("Filtrarea a fost facuta!")


def filtrare_concurenti_care_au_scorul_mai_mic_decat_un_numar_dat_ui(concurenti,istoric):
    """
    
    Args:
        concurenti:
        istoric: o lista cu valorile programului inainte de fiecare noua operatie
    Returns:

    """
    istoric.append(concurenti)
    scor = int(input("Scorul este :"))
    _, mesaj = concurentii_scor_mai_mic_decat_cel_dat(concurenti, scor)
    print("Filtrarea a fost facuta!")


def afisare_concurenti(concurenti):
    """
    Functia afiseaza concurentii din lista concurenti
    Args:
        concurenti: o lista cu concurenti
    Returns:-
    
    """
    for index in range(len(concurenti)):
        concurent = concurenti[index]
        print(f"Nr_lista : {index} | Id : {concurent['id_concurent']} | Nume : {concurent['nume_concurent']}")
        for index_proba,scor_proba in enumerate(concurent['scoruri_concurent']):
            print(f"{index_proba}: {scor_proba}")
        print(f"Scor final : {concurent['scor_final']}")

    if len(concurenti) == 0:
        print('Lista este goala!')


