from validare import *

def adaugare_concurent(concurenti,concurent):
    """
    Functia adauga un concurent daca datele lui sunt valide
    Args:
        concurenti: o lista de concurenti
        concurent: un concurent

    Returns:
        True,"" daca datele lui sunt valide
        False,erorile un string in care sunt scrise toate erorile
    """
    try:
        validare_concurent(concurent)
        concurenti.append(concurent)
        return True,""
    except ValueError as e:
        return False,e

def convertire_string_la_float_si_punere_in_lista(scoruri):
    """
    Functia converteste un string de numere intr o lista cu elemente de tip float
    Args:
        scoruri: un string cu scoruri

    Returns:
        o lista cu numere de tip float lista_scoruri , suma tuturor elementelor din lista  un numar de tip float scor_final
    """
    scor_final = 0
    lista_scoruri_string = scoruri.split(" ")
    lista_scoruri_float = []
    for i in range(len(lista_scoruri_string)):
        lista_scoruri_float.append(float(lista_scoruri_string[i]))
        scor_final += lista_scoruri_float[i]

    return lista_scoruri_float,scor_final


def insereaza_scor_la_proba(concurenti,id_concurent,numarul_probei,scor_de_inserat):
    """
    Functia insereaza scorul scor_de_inserat de la proba care are numarul numarul_probei de la  concurentul din lista concurenti cu id-ul ID-concurent
    Args:
        concurenti: o lista de concurenti
        id_concurent:  un numar intreg strict pozitiv
        numarul_probei: un numar natural , mai mic sau egal cu 10
        scor_de_inserat: un numarul natural cuprins intre 1.0-10.0

    Returns:
        True,"" daca datele sunt corespunzatoare
        False,erorile un string in care sunt scrise toate erorile

    """
    try:
        valid_insert_scor_la_proba(concurenti, id_concurent, numarul_probei, scor_de_inserat)
        for concurent in concurenti:
            if concurent['id_concurent'] == id_concurent:
                concurent['scoruri_concurent'].insert(numarul_probei, scor_de_inserat)
                concurent['scor_final'] += scor_de_inserat
        return True,""
    except ValueError as e:
        return False,e

def stergere_scor_pentru_concurent(concurenti, id_concurent, numarul_probei):
    """
    Sterge scorul la numarul probei dorite pentru concurentul cu id_concurent din lista concurenti
    Args:
        concurenti: o lista de concurenti
        id_concurent: un numar natural pozitiv
        numarul_probei: un numar natural , mai mic sau egal cu 10

    Returns:
        True,"" daca datele sunt corespunzatoare
        False,erorile un string in care sunt scrise toate erorile
    """
    try:
        validare_id_concurent(concurenti, id_concurent)
        validare_numar_proba(concurenti, id_concurent, numarul_probei)
        for concurent in concurenti:
            if get_id_concurent(concurent) == id_concurent:
                concurent['scor_final'] -= get_scor_la_o_anumita_proba(concurent, numarul_probei)
                concurent['scoruri_concurent'].pop(numarul_probei)
                break
        return True,""
    except ValueError as e:
        return False,e



def sterge_scor_pentru_interval_de_concurenti(concurenti, start_interval, end_interval, proba_care_trebuie_sa_fie_stearsa):
    """
    Sterge proba numar intreg proba_care_trebuie_sa_fie_stearsa de la fiecare concurent din lista concurenti , din intervalul start_interval-end_interval
    Args:
        concurenti: o lista de concurenti
        start_interval: numar intreg , pozitiv
        end_interval:  numar intreg , pozitiv end_interval >= start_interval
        proba_care_trebuie_sa_fie_stearsa: numar intreg , pozitiv cuprins intre 1-10

    Returns:-
        True,"" daca datele sunt corespunzatoare
        False,erorile un string in care sunt scrise toate erorile
    """
    try:
        validare_indexi_cautare_in_interval_concurenti(concurenti, start_interval, end_interval)
        validare_disponibilitate_proba_care_trebuie_sa_fie_stearsa(concurenti, proba_care_trebuie_sa_fie_stearsa,start_interval, end_interval)
        for i in range(start_interval,end_interval+1):
            concurent = concurenti[i]
            stergere_scor_pentru_concurent(concurenti,get_id_concurent(concurent),proba_care_trebuie_sa_fie_stearsa)
        return True,""
    except ValueError as e:
        return False,e


def inlocuieste_scorul_de_la_un_concurent(concurenti,id_concurent,numar_proba_la_care_inlocuim,scorul_cu_care_dorim_sa_inlocuim):
    """
    Functia modifica scorul la o proba numar_proba_la_care_inlocuim numar intreg , cu valoarea intreaga scorul_cu_care_dorim_sa in lista concurenti, la concurentul din lista concurenti cu idul
    Args:
        concurenti: o lista de concurenti
        id_concurent: un numar intreg , pozitiv
        numar_proba_la_care_inlocuim: un numar intreg , pozitiv cuprins intre 1-10
        scorul_cu_care_dorim_sa_inlocuim: un numar de tip float , cuprins intre 1.0-10.0

    Returns:
        True,"" daca datele sunt corespunzatoare
        False,erorile un string in care sunt scrise toate erorile
    """
    try:
        validare_id_concurent(concurenti, id_concurent)
        validare_numar_proba(concurenti, id_concurent,numar_proba_la_care_inlocuim)
        validare_scor_concurent(scorul_cu_care_dorim_sa_inlocuim)
        for concurent in concurenti:
            if get_id_concurent(concurent) == id_concurent:
                lista_scoruri_concurent = concurent['scoruri_concurent']
                concurent['scor_final'] = concurent['scor_final'] + scorul_cu_care_dorim_sa_inlocuim - lista_scoruri_concurent[numar_proba_la_care_inlocuim]
                lista_scoruri_concurent[numar_proba_la_care_inlocuim] = scorul_cu_care_dorim_sa_inlocuim
                return True,""
    except ValueError as e:
        return False,e







def concurentii_scor_mai_mic_decat_cel_dat(concurenti,scor_de_comparat):
    """
    Afiseaza toti concurentii care au scorul mai mic decat scorul scor_de_comparat numar de tip float
    Args:
        concurenti: o lista cu concurenti
        scor_de_comparat: un numar de tip float , cuprins intre 1.0-10.0

    Returns:
        True,"" daca datele sunt corespunzatoare
        False,erorile un string in care sunt scrise toate erorile

    """
    lista_noua = []
    for concurent in concurenti:
        if get_suma_tuturor_scorurilor(concurent) < scor_de_comparat:
            lista_noua.append(concurent)
    return lista_noua,""

def tipareste_ordonat_dupa_scor(concurenti,optiune):
    """
    Functia tipareste concurentii in ordine crescatoare/descrescatoare dupa scorul final
    Args:
        concurenti: o lista cu concurenti
        optiune : 1)crescator
                  2)descrescator

    Returns: -
        O lista in ordine crescatoare/descrescator , neafectand lista originala
    """

    concurenti_copie = concurenti[:]
    if optiune == 1:
        sortare_crescatoare_lista(concurenti_copie)
    else :
        sortare_descrescatoare_lista(concurenti_copie)
    return concurenti_copie,""

def sortare_crescatoare_lista(concurenti_copie):
    """
    Functia sorteaza crescator scorurile concurentilor
    Args:
        concurenti_copie: o lista cu concurenti:

    Returns:-

    """
    for i in range(len(concurenti_copie)-1):
        for j in range(i+1,len(concurenti_copie)):
            if get_suma_tuturor_scorurilor(concurenti_copie[i]) > get_suma_tuturor_scorurilor(concurenti_copie[j]):
                aux = concurenti_copie[i]
                concurenti_copie[i] = concurenti_copie[j]
                concurenti_copie[j] = aux


def sortare_descrescatoare_lista(concurenti_copie):
    """
    Functia sorteaza descrescator scorurile concurentilor
    Args:
        concurenti_copie: o lista cu concurenti:

    Returns:-
    """
    for i in range(len(concurenti_copie)-1):
        for j in range(i+1,len(concurenti_copie)):
            if get_suma_tuturor_scorurilor(concurenti_copie[i]) < get_suma_tuturor_scorurilor(concurenti_copie[j]):
                aux = concurenti_copie[i]
                concurenti_copie[i] = concurenti_copie[j]
                concurenti_copie[j] = aux


def ordoneaza_concurentii_cu_scor_mai_mare_decat_scorul_dat(concurenti,optiune,scor_de_comparat):
    """
    Functia tipareste concurentii care au scorul mai mare decat scorul final cerut in ordine crescatoare
    Args:
        concurenti : o lista cu concurenti
        optiune : 1)crescator 2)descrescator
        scor_de_comparat : un numar de tip float
    Returns:
        lista_noua,""
    """
    lista_noua = []
    if optiune == 1:
        sortare_crescatoare_lista(concurenti)
    else:
        sortare_descrescatoare_lista(concurenti)
    for concurent in concurenti:
        if get_suma_tuturor_scorurilor(concurent) > scor_de_comparat:
            lista_noua.append(concurent)
    return lista_noua, ""




def calculeaza_media_scorurilor_interval_dat(concurenti, primul_concurent, ultimul_concurent) :
    """
    Functia calculeaza media scorurilor finale din intervalul dat
    Args:
        concurenti: o lista cu concurenti
        primul_concurent: un numar intreg pozitiv
        ultimul_concurent: un numar intreg pozitiv

    Returns:
        True,media un numar float,mesajul un string , daca totul a mers bine
        False,0.0 daca nu a mers,eroarea un string daca nu a functionat bine
    """
    try:
        rezultat = 0
        validare_indexi_cautare_in_interval_concurenti(concurenti,primul_concurent,ultimul_concurent)

        for i in range (primul_concurent,ultimul_concurent + 1):
            rezultat += get_suma_tuturor_scorurilor(concurenti[i])

        numar_concurenti_interval = ultimul_concurent - primul_concurent + 1
        return True,rezultat / numar_concurenti_interval , ""
    except ValueError as e:
        return False,0.0,e

def calcuealza_scor_minim_interval_participanti(concurenti,start_interval,end_interval):
    """
    Funcia calculeaza media scorurilor finale din intervalul dat
    Args:
        concurenti: o lista cu concurenti
        start_interval: un numar natural reprezentand indexul de unde incepe intervalul
        end_interval: un numar natural reprezentand indexul unde se termina intervalul

    Returns:
        True,scor_minim,""  - daca este posibila accesarea indexilor unde scor_minim este un  numar de tip float
        Flase,-1,e - daca nu este posibila accesarea indexilor unde e este un string cu erori
    """
    try:
        validare_indexi_cautare_in_interval_concurenti(concurenti,start_interval,end_interval)
        scor_minim = 999999
        for i in range (start_interval,end_interval + 1):
            concurent = concurenti[i]
            if get_suma_tuturor_scorurilor(concurent) < scor_minim:
                scor_minim = get_suma_tuturor_scorurilor(concurent)


        return True,scor_minim,""
    except ValueError as e:
        return False,-1,e



def tipareste_concurentii_care_au_scorul_multiplu_de_numar(concurenti,numar):
    """
    Functia pune intr o lista noua toti participantii care au scorul final multiplu de numar
    Args:
        concurenti: o lista cu concurenti
        numar: un numar intreg pozitiv

    Returns:
        lista_noua,"" daca exista participanti care au scorul multiplu de numar
        lista_noua,mesaj un string daca nu exista participanti care au scorul multiplu de numar
    """
    lista_noua = []
    for concurent in concurenti:
        if get_suma_tuturor_scorurilor(concurent) % numar == 0:
            lista_noua.append(concurent)

    if len(lista_noua) == 0:
        return lista_noua,"Nu exista participanti care sa aiba scorul multiplu de numarul dat!"
    return lista_noua,""


def undo(concurenti, istoric):
    """
    Functia reintoarce lista la pasul anterior
    Args:
        concurenti: o lista cu concurenti
        istoric: o lista cu valorile programului inainte de fiecare noua operatie

    Returns:
        True daca s a reusit undo
        False altfel

    """
    if not istoric:
        print("Istoricul este gol!")
        return False

    before = istoric.pop()
    concurenti[:] = before
    return True

def actualizeaza_istoric(concurenti,istoric):
    """"
    Functia actualizeaza lista istoric , adaugand in ea noul pas
    Args:
        concurenti: o lista cu concurenti
        istoric: o lista cu valorile programului inainte
    """
    stare_noua = []
    for concurent in concurenti:
        scoruri_concurent = get_scorurile_concurentului(concurent)
        lista_scoruri_copie = scoruri_concurent[:]

        concurent_copie = {
            'id_concurent': get_id_concurent(concurent),
            'nume_concurent': get_nume_concurent(concurent),
            'scoruri_concurent': lista_scoruri_copie,
            'scor_final': get_suma_tuturor_scorurilor(concurent),
        }

        stare_noua.append(concurent_copie)
    istoric.append(stare_noua)



