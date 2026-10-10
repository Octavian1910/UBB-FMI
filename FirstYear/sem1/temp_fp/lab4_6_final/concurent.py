
def creeare_concurent(id_concurent, nume_concurent, scoruri_concurent,scor_final):
    """
    Functia creeaza un concurent cu id_concurent un numar intreg pozitv, nume_concurent un string nevid, scoruri_concurent un string cu numere separate prin spatiu
    Args:
        id_concurent: un numar intreg pozitiv , id_concurent >= 0
        nume_concurent: un string nevid
        scoruri_concurent:  un string cu numere pozitive de tip float separate prin spatiu
        scor_final : O valoare de tip float , reprezentant suma tuturor valorilor din scoruri_concurent
    Returns:
            Un concurent care are id_concurent, nume_concurent, scoruri_concurent,suma scorurilor

    """
    return {
        'id_concurent': id_concurent,
        'nume_concurent': nume_concurent,
        'scoruri_concurent': scoruri_concurent,
        'scor_final': scor_final
    }


def get_id_concurent(concurent):
    """
    Functia get_id_concurent(concurent) returneaza id-ul concurentului
    Args:
        concurent: un concurent care are si un id

    Returns:
        id-ul concurentului un numar intreg
    """
    return concurent['id_concurent']

def get_nume_concurent(concurent):
    """
    Functia returneaza numele concurentului concurent
    Args:
        concurent: un concurent care detine si un nume de tip string

    Returns:
        numele concurentului care este un string

    """
    return concurent['nume_concurent']

def get_scorurile_concurentului(concurent):
    """
    Functia returneaza lista cu scorurile concurentului , unde scorurile sunt de tip float
    Args:
        concurent: un concurent care are si o lista cu scoruri

    Returns:
        o lista de numere de tip float unde se afla scorurile concurentului
    """
    return concurent['scoruri_concurent']

def get_numar_probe_concurent(concurent):
    """
    Functia returneaza numarul de probe la care a participat concurentul concurent
    Args:
        concurent: un concurent care detine o lista de numere pozitive de tip float cuprinse intre 1.00 si 10

    Returns:
        numarul de elemente din lista de numere pozitive de tip float
    """
    return len(get_scorurile_concurentului(concurent))

def get_scor_la_o_anumita_proba(concurent,numar_proba):
    """
    Functia returneaza scorul de la proba dorita
    Args:
        concurent: un concurent care are o lista de numere pozitive de tip float
        numar_proba: un numar intreg pozitiv cuprins intre 1 si 10

    Returns:
        Un numar de tip float
    """
    lista_scoruri = get_scorurile_concurentului(concurent)
    return lista_scoruri[numar_proba]


def get_suma_tuturor_scorurilor(concurent) :
    """
    Returneaza suma tutor scorurilor , adica scorul final
    Args:
        concurent: un concurent

    Returns:
        Un numar de tip float
    """
    return concurent['scor_final']


def stergere_scoruri(concurent):
    """
    Functia sterge toate scoruirle concurentului
    Args:
        concurent: un concurent

    Returns:
        -
    """
    concurent['scor_final'] = 0
    concurent['scoruri_concurent'] = []