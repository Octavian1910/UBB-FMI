from concurent import *

def validare_concurent(concurent):
    '''
    Functie care valideaza daca informatia din concurent este valida
    :param concurent: un concurent
    :return: True daca totul este ok
    :raises: ValueError cu mesajul:
            id invalid!\n - daca idul este <0
            nume invalid!\n - daca nume este vid
            valoare invalida!\n - daca un scor din lista este < 1.0
    '''
    erori = []
    if(get_id_concurent(concurent) < 0 ):
        erori.append( "Id invalid!\n")
    if(get_nume_concurent(concurent) == ""):
        erori.append( "Nume concurent invalid!\n")
    scoruri = get_scorurile_concurentului(concurent)
    if len(scoruri) > 10:
        erori.append("Prea multe probe!\n")
    else :
        for sc in scoruri:
            if sc < 1.0 or sc > 10.0:
                erori.append("Scor invalid!\n")
                break

    if(len(erori)>0):
        raise ValueError("".join(erori))
    else :  return True,""

def validare_scor_concurent(scor_de_introdus):
    '''
    Verifica daca noul scor care trebuie introdus respecta este cuprins intre 1.0-10.0
    Args:
        scor_de_introdus: un numar pozitiv de tip float , cuprins intre 1.0 - 10.0
    Returns:
        true daca scor este numar pozitiv cuprin intre 1.0 - 10.0 si are loc in lista
        :raises: caz contrar
    '''
    if(scor_de_introdus >= 1.0 and scor_de_introdus <= 10.0) :
        return True,""
    else :
        raise ValueError("Scorul trebuie să fie un număr cuprins între 1.0 și 10.0.")

def validare_id_concurent(concurenti,id_concurent):
    '''
    Functia verifica daca id ul concurentului se poate accesa
    Args:
        id_concurent: un numar intreg

    Returns:
        true,"" daca id ul concurentului se poate accesa
        :raises: Raise ValueError daca ID ul nu exista in lista
    '''
    erori = []
    gasit = False
    for concurent in concurenti:
        if get_id_concurent(concurent) == id_concurent:
            gasit = True

    if gasit :
        return True,""
    else :
        erori.append("ID-ul nu este potrivit!")
        raise ValueError("".join(erori))



def validare_numar_proba(concurenti, id_concurent,numarul_probei):
    '''
    Verifica daca exista proba unde dorim sa inseram noul numar
    Args:
        concurenti: o lista cu concurenti
        id_concurent: un numar intreg
        nr_proba: un numar intreg

    Returns:
        true daca exista loc pentru a insera proba
        Raise ValueError altfel
    '''

    erori = []
    concurent_gasit = []
    for concurent in concurenti:
        if concurent['id_concurent'] == id_concurent:
            concurent_gasit = concurent

    nr_probe = get_numar_probe_concurent(concurent_gasit)
    if(nr_probe > numarul_probei and numarul_probei >= 0):
        return True,""
    else :
        erori.append("Nu exista proba!")
        raise ValueError("".join(erori))


def valid_insert_scor_la_proba(concurenti,id_concurent,numarul_probei,scor_de_inserat):
    '''
    Functia verifica date se poate insera scorul scor_de_inserat numar intreg , la proba intreaga numarul_probei cu scorul de tip float scor_de_inserat
    Args:
        concurenti: o lista cu concurenti
        id_concurent: id ul concurentului , nr pozitiv > 0
        numarul_probei:  numar intreg
        scor_de_inserat:  float cuprin intre 1.0-10.0

    Returns:
        true daca este posibil
        Raise ValueError altfel
    '''

    try:
        validare_id_concurent(concurenti, id_concurent)
        validare_scor_concurent(scor_de_inserat)
        validare_numar_proba(concurenti, id_concurent, numarul_probei)
        return True,""
    except ValueError:
        raise ValueError("Datele nu sunt bune.")


def validare_indexi_cautare_in_interval_concurenti(concurenti, start_interval, end_interval):
    '''
    Functia verifica daca este posibila cautarea in intervalul care incepe de la numarul intreg start_interval si se termina la numarul intreg end_interval
    Args:
        concurenti: o lista cu concurenti
        start_interval: numar intreg pozitiv de unde incepem
        end_interval:  numar intreg pozitiv unde terminam

    Returns:
        True daca este posibila cautarea
        Raise ValueError altfel
    '''
    numar_concurenti = get_numar_concurenti(concurenti)
    if(start_interval <= numar_concurenti and end_interval <= numar_concurenti and start_interval <= end_interval):
        return True,""
    else :
        raise ValueError("Indexii nu sunt buni!")


def get_numar_concurenti(concurenti):
    '''
    Returneaza numarul de concurenti din lista concurentilor
    Args:
        concurenti: o lista cu concurenti

    Returns:
        un numar intreg

    '''
    return len(concurenti)

def validare_disponibilitate_proba_care_trebuie_sa_fie_stearsa(concurenti,numar_proba_care_trebuie_sa_fie_stearsa,start_interval,end_interval):
    """
    Verifica pentru intervalul start_concurenti-end_concurenti , daca fiecare concurent din lista concurenti a particiapt la proba respectiva
    Args:
        concurenti: o lista cu concurenti
        numar_proba_care_trebuie_sa_fie_stearsa: un numar intreg pozitiv <= 10
        start_interval: numar intreg pozitiv de unde incepem
        end_interval:  numar intreg pozitiv unde terminam
    Returns:
        True daca este posibila cautarea
        Raise ValueError altfel
    """
    for i in range(start_interval, end_interval + 1):
        concurent = concurenti[i]

        numar_probe_curent = get_numar_probe_concurent(concurent)

        if numar_proba_care_trebuie_sa_fie_stearsa < 0 or numar_proba_care_trebuie_sa_fie_stearsa >= numar_probe_curent:
            raise ValueError("Proba nu exista!")

    return True,""

def validare_impartitor(impartitor):
    """
    Verifica daca impartitorul este un numar bun
    Args:
        impartitor: un numar natural intreg

    Returns:
        True daca impartitorul este bun
        Raise ValueError altfel

    """
    if impartitor != 0:
        return True,""
    else:
        raise ValueError("Impartitorul nu este bun!")

