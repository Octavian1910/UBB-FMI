from service import *


def test_creeaza_concurent():
    id_concurent = 1
    nume_concurent = "Octavian"
    scoruri_concurent_str = "1 2 3 4 5 6 7 8 9 10"
    scoruri_float, scor_final = convertire_string_la_float_si_punere_in_lista(scoruri_concurent_str)
    concurent = creeare_concurent(id_concurent, nume_concurent, scoruri_float, scor_final)
    assert (get_id_concurent(concurent) == id_concurent)
    assert (get_nume_concurent(concurent) == nume_concurent)
    assert (get_scorurile_concurentului(concurent) == [1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0])
    assert (get_suma_tuturor_scorurilor(concurent) == 55.0)  # Verifică și scorul final dacă funcția de conversie îl calculează


def test_adaugare_concurent():
    scoruri_concurent_str = "10 9 8 7 -5"
    scoruri_concurent, scor_final = convertire_string_la_float_si_punere_in_lista(scoruri_concurent_str)
    concurent = creeare_concurent(2, "Adriana", scoruri_concurent, scor_final)
    try:
        validare_concurent(concurent)
        assert False
    except ValueError as e:
        assert "Scor invalid!" in str(e)

    scoruri_concurent_str = "1 2 3 4 5 6 7 8 9 10 11"
    scoruri_concurent, scor_final = convertire_string_la_float_si_punere_in_lista(scoruri_concurent_str)
    concurent = creeare_concurent(3, "Lambo", scoruri_concurent, scor_final)
    try:
        validare_concurent(concurent)
        assert False
    except ValueError as e:
        assert "Prea multe probe!" in str(e)

    scoruri_concurent_str = "1 2 3 4 5 6 7 8 9 10"
    scoruri_concurent, scor_final = convertire_string_la_float_si_punere_in_lista(scoruri_concurent_str)
    concurent = creeare_concurent(4, "", scoruri_concurent, scor_final)
    try:
        validare_concurent(concurent)
        assert False
    except ValueError as e:
        assert "Nume concurent invalid!" in str(e)

    scoruri_concurent_str = "1 2 3 4 5 6 7 8 9 10"
    scoruri_concurent, scor_final = convertire_string_la_float_si_punere_in_lista(scoruri_concurent_str)
    concurent = creeare_concurent(-1, "ValidName", scoruri_concurent, scor_final)
    try:
        validare_concurent(concurent)
        assert False
    except ValueError as e:
        assert "Id invalid!" in str(e)

    scoruri_concurent_str = "1 2 3 4 5 6 7 8 9 10"
    scoruri_concurent, scor_final = convertire_string_la_float_si_punere_in_lista(scoruri_concurent_str)
    concurent = creeare_concurent(5, "CazDeSucces", scoruri_concurent, scor_final)

    try:
        rezultat, eroare = validare_concurent(concurent)
        assert rezultat is True
    except ValueError:
        assert False


def test_inserare_scor_concurent():
    concurenti = []
    scoruri_float, scor_final = convertire_string_la_float_si_punere_in_lista("1.0 5.0 9.0 8.0 7.0")
    concurent1 = creeare_concurent(1, "Octavian", scoruri_float, scor_final)
    scoruri_float, scor_final = convertire_string_la_float_si_punere_in_lista("1.0 5.0 4.0 8.0 7.0 5.0")
    concurent2 = creeare_concurent(2, "Adriana", scoruri_float, scor_final)
    concurenti.append(concurent1)
    concurenti.append(concurent2)

    try:
        validare_id_concurent(concurenti, 5)
        assert False
    except ValueError as e:
        assert "ID-ul nu este potrivit" in str(e)

    exceptie_ridicata = False
    try:
        validare_scor_concurent(0.25)
        assert False
    except ValueError:
        exceptie_ridicata = True
    assert exceptie_ridicata is True

    raspuns, mesaj = validare_id_concurent(concurenti, get_id_concurent(concurent2))
    assert raspuns == True

    raspuns, mesaj = validare_scor_concurent(5.0)
    assert raspuns is True

    try:
        valid_insert_scor_la_proba(concurenti, 1, 10, 2.0)
        assert False
    except ValueError as e:
        assert "Datele nu sunt bune." in str(e)

    rezultat, mesaj = valid_insert_scor_la_proba(concurenti, 1, 1, 2.0)
    assert rezultat is True

    insereaza_scor_la_proba(concurenti, 1, 1, 2.5)
    assert get_scorurile_concurentului(concurent1) == [1.0, 2.5, 5.0, 9.0, 8.0, 7.0]
    # Ar trebui să recalculați și scorul final dacă funcția de inserare o face


def test_sterge_scorul_participant_dat():
    concurenti = []
    scoruri_float, scor_final = convertire_string_la_float_si_punere_in_lista("1.0 5.0 9.0 8.0 7.0")
    concurent1 = creeare_concurent(1, "Octavian", scoruri_float, scor_final)
    scoruri_float, scor_final = convertire_string_la_float_si_punere_in_lista("1.0 5.0 4.0 8.0 7.0 5.0")
    concurent2 = creeare_concurent(2, "Adriana", scoruri_float, scor_final)
    concurenti.append(concurent1)
    concurenti.append(concurent2)

    rezultat, mesaj = stergere_scor_pentru_concurent(concurenti, 1, 1)
    assert rezultat is True
    assert get_scorurile_concurentului(concurent1) == [1.0, 9.0, 8.0, 7.0]

    rezultat, mesaj = stergere_scor_pentru_concurent(concurenti, 2, 0)
    assert rezultat is True
    assert get_scorurile_concurentului(concurent2) == [5.0, 4.0, 8.0, 7.0, 5.0]

    rezultat, mesaj = stergere_scor_pentru_concurent(concurenti, 2, 4)
    assert rezultat is True
    assert get_scorurile_concurentului(concurent2) == [5.0, 4.0, 8.0, 7.0]

    rezultat, eroare = stergere_scor_pentru_concurent(concurenti, 99, 0)
    assert rezultat is False
    assert "ID-ul nu este potrivit!" in str(eroare)

    rezultat, eroare = stergere_scor_pentru_concurent(concurenti, 1, 9)
    assert rezultat is False
    assert "Nu exista proba!" in str(eroare)

    rezultat, eroare = stergere_scor_pentru_concurent(concurenti, 1, -1)
    assert rezultat is False
    assert "Nu exista proba!" in str(eroare)


def test_sterge_scor_pentru_interval_de_concurenti():
    concurenti = []
    scoruri_float, scor_final = convertire_string_la_float_si_punere_in_lista("1.0 2.0 3.0 4.0 5.0")
    c1 = creeare_concurent(1, "Octavian", scoruri_float, scor_final)
    scoruri_float, scor_final = convertire_string_la_float_si_punere_in_lista("5.0 6.0 7.0 8.0 9.0")
    c2 = creeare_concurent(2, "Adriana", scoruri_float, scor_final)
    scoruri_float, scor_final = convertire_string_la_float_si_punere_in_lista("10.0 9.0 8.0 7.0 6.0")
    c3 = creeare_concurent(3, "Mihai", scoruri_float, scor_final)
    scoruri_float, scor_final = convertire_string_la_float_si_punere_in_lista("1.0 3.0 5.0 7.0 9.0")
    c4 = creeare_concurent(4, "Elena", scoruri_float, scor_final)
    scoruri_float, scor_final = convertire_string_la_float_si_punere_in_lista("2.0 4.0 6.0 8.0 10.0")
    c5 = creeare_concurent(5, "Vlad", scoruri_float, scor_final)
    concurenti.extend([c1, c2, c3, c4, c5])

    raspuns, mesaj = sterge_scor_pentru_interval_de_concurenti(concurenti, 2, 3, 1)
    assert raspuns is True
    assert get_scorurile_concurentului(c3) == [10.0, 8.0, 7.0, 6.0]
    assert get_scorurile_concurentului(c4) == [1.0, 5.0, 7.0, 9.0]
    assert get_scorurile_concurentului(c5) == [2.0, 4.0, 6.0, 8.0, 10.0]


def test_inlocuieste_scorul_de_la_un_concurent():
    concurenti = []
    scoruri_float, scor_final = convertire_string_la_float_si_punere_in_lista("1.0 5.0 9.0 8.0 7.0")
    c1 = creeare_concurent(1, "Octavian", scoruri_float, scor_final)
    scoruri_float, scor_final = convertire_string_la_float_si_punere_in_lista("2.0 4.0 6.0 8.0 10.0")
    c2 = creeare_concurent(2, "Adriana", scoruri_float, scor_final)
    concurenti.extend([c1, c2])

    raspuns, mesaj = inlocuieste_scorul_de_la_un_concurent(concurenti, 1, 2, 5.0)
    assert raspuns is True
    assert get_scor_la_o_anumita_proba(c1, 2) == 5.0

    raspuns, mesaj = inlocuieste_scorul_de_la_un_concurent(concurenti, 99, 1, 5.0)
    mesaj = str(mesaj)
    assert raspuns is False
    assert "ID-ul nu este potrivit!" in mesaj

    raspuns, mesaj = inlocuieste_scorul_de_la_un_concurent(concurenti, 1, 10, 5.0)
    mesaj = str(mesaj)
    assert raspuns is False
    assert "proba" in mesaj

    raspuns, mesaj = inlocuieste_scorul_de_la_un_concurent(concurenti, 1, 1, 15.0)
    mesaj = str(mesaj)
    assert raspuns is False
    assert "Scorul" in mesaj


def test_tiparire_concurenti_cu_scor_mai_mic_decat_scorul_dat():
    concurenti = []
    scoruri_float, scor_final = convertire_string_la_float_si_punere_in_lista("1.25 5.6 9.8 8.0 7.0")
    concurent1 = creeare_concurent(1, "Octavian", scoruri_float, scor_final)  # 31.65
    scoruri_float, scor_final = convertire_string_la_float_si_punere_in_lista("1.0 5.0 4.0 8.0 7.0 5.0")
    concurent2 = creeare_concurent(2, "Adriana", scoruri_float, scor_final)  # 30.0
    scoruri_float, scor_final = convertire_string_la_float_si_punere_in_lista("9.5 9.0 10.0 8.5")
    concurent3 = creeare_concurent(3, "Mihai", scoruri_float, scor_final)  # 37.0
    scoruri_float, scor_final = convertire_string_la_float_si_punere_in_lista("7.0 6.5 7.5 8.0 7.0")
    concurent4 = creeare_concurent(4, "Elena", scoruri_float, scor_final)  # 36.0
    scoruri_float, scor_final = convertire_string_la_float_si_punere_in_lista("6.0 6.0 6.0 6.0 6.0")
    concurent5 = creeare_concurent(5, "Vlad", scoruri_float, scor_final)  # 30.0
    concurenti.append(concurent1)
    concurenti.append(concurent2)
    concurenti.append(concurent3)
    concurenti.append(concurent4)
    concurenti.append(concurent5)
    lista_de_tiparit, mesaj = concurentii_scor_mai_mic_decat_cel_dat(concurenti, 35)
    assert lista_de_tiparit == [concurent1, concurent2, concurent5]
    assert lista_de_tiparit != [concurent1, concurent2, concurent4]


def test_tipareste_scor_mai_mic_decat_cel_dat():
    scoruri_float, scor_final = convertire_string_la_float_si_punere_in_lista("1.25 5.6 9.8 8.0 7.0")
    c1 = creeare_concurent(1, "Octavian", scoruri_float, scor_final)  # total = 31.65
    scoruri_float, scor_final = convertire_string_la_float_si_punere_in_lista("1.0 5.0 4.0 8.0 7.0 5.0")
    c2 = creeare_concurent(2, "Adriana", scoruri_float, scor_final)  # total = 30.0
    scoruri_float, scor_final = convertire_string_la_float_si_punere_in_lista("9.5 9.0 10.0 8.5")
    c3 = creeare_concurent(3, "Mihai", scoruri_float, scor_final)  # total = 37.0
    scoruri_float, scor_final = convertire_string_la_float_si_punere_in_lista("7.0 6.5 7.5 8.0 7.0")
    c4 = creeare_concurent(4, "Elena", scoruri_float, scor_final)  # total = 36.0
    scoruri_float, scor_final = convertire_string_la_float_si_punere_in_lista("6.0 6.0 6.0 6.0 6.0")
    c5 = creeare_concurent(5, "Vlad", scoruri_float, scor_final)  # total = 30.0
    concurenti = [c1, c2, c3, c4, c5]

    lista_de_tiparit, mesaj = concurentii_scor_mai_mic_decat_cel_dat(concurenti, 35)

    assert lista_de_tiparit == [c1, c2, c5]
    assert lista_de_tiparit != [c1, c2, c4]


def test_tipareste_ordonat_dupa_scor():
    scoruri_float, scor_final = convertire_string_la_float_si_punere_in_lista("1.0 2.0 3.0")
    c1 = creeare_concurent(1, "Octavian", scoruri_float, scor_final)  # total = 6
    scoruri_float, scor_final = convertire_string_la_float_si_punere_in_lista("4.0 4.0 4.0")
    c2 = creeare_concurent(2, "Adriana", scoruri_float, scor_final)  # total = 12
    scoruri_float, scor_final = convertire_string_la_float_si_punere_in_lista("9.0 8.0 7.0")
    c3 = creeare_concurent(3, "Mihai", scoruri_float, scor_final)  # total = 24
    concurenti = [c1, c2, c3]

    lista_cresc, mesaj = tipareste_ordonat_dupa_scor(concurenti, 1)
    assert lista_cresc == [c1, c2, c3]

    lista_desc, mesaj = tipareste_ordonat_dupa_scor(concurenti, 2)
    assert lista_desc == [c3, c2, c1]


def test_tipareste_concurentii_cu_scor_mai_mare_decat_scorul_dat_ordonati():
    scoruri_float, scor_final = convertire_string_la_float_si_punere_in_lista("1.0 2.0 3.0")
    c1 = creeare_concurent(1, "Octavian", scoruri_float, scor_final)  # total = 6
    scoruri_float, scor_final = convertire_string_la_float_si_punere_in_lista("4.0 5.0 6.0")
    c2 = creeare_concurent(2, "Adriana", scoruri_float, scor_final)  # total = 15
    scoruri_float, scor_final = convertire_string_la_float_si_punere_in_lista("9.0 9.0 8.0")
    c3 = creeare_concurent(3, "Mihai", scoruri_float, scor_final)  # total = 26
    scoruri_float, scor_final = convertire_string_la_float_si_punere_in_lista("10.0 10.0 10.0")
    c4 = creeare_concurent(4, "Elena", scoruri_float, scor_final)  # total = 30
    concurenti = [c1, c2, c3, c4]

    lista_cresc, mesaj = ordoneaza_concurentii_cu_scor_mai_mare_decat_scorul_dat(concurenti, 1, 10)
    assert lista_cresc == [c2, c3, c4]

    lista_desc, mesaj = ordoneaza_concurentii_cu_scor_mai_mare_decat_scorul_dat(concurenti, 2, 10)
    assert lista_desc == [c4, c3, c2]


def test_calculeaza_media_scorurilor_interval_dat():
    scoruri_float, scor_final = convertire_string_la_float_si_punere_in_lista("1.0 2.0 3.0")
    c1 = creeare_concurent(1, "Octavian", scoruri_float, scor_final)  # total = 6
    scoruri_float, scor_final = convertire_string_la_float_si_punere_in_lista("4.0 5.0 6.0")
    c2 = creeare_concurent(2, "Adriana", scoruri_float, scor_final)  # total = 15
    scoruri_float, scor_final = convertire_string_la_float_si_punere_in_lista("7.0 8.0 9.0")
    c3 = creeare_concurent(3, "Mihai", scoruri_float, scor_final)  # total = 24
    scoruri_float, scor_final = convertire_string_la_float_si_punere_in_lista("10.0 10.0 10.0")
    c4 = creeare_concurent(4, "Elena", scoruri_float, scor_final)  # total = 30
    concurenti = [c1, c2, c3, c4]

    functioneaza, medie, mesaj = calculeaza_media_scorurilor_interval_dat(concurenti, 0, 2)
    assert functioneaza is True
    eroare = 0.0001
    assert abs(medie - 15.0) < eroare
    assert mesaj == ""

    functioneaza, medie, mesaj = calculeaza_media_scorurilor_interval_dat(concurenti, 1, 10)
    assert functioneaza is False
    assert medie == 0.0
    assert "Indexii" in str(mesaj)


def test_calcuealza_scor_minim_interval_participanti():
    scoruri_float, scor_final = convertire_string_la_float_si_punere_in_lista("1.0 2.0 3.0")
    c1 = creeare_concurent(1, "Octavian", scoruri_float, scor_final)  # total = 6
    scoruri_float, scor_final = convertire_string_la_float_si_punere_in_lista("4.0 5.0 6.0")
    c2 = creeare_concurent(2, "Adriana", scoruri_float, scor_final)  # total = 15
    scoruri_float, scor_final = convertire_string_la_float_si_punere_in_lista("7.0 8.0 9.0")
    c3 = creeare_concurent(3, "Mihai", scoruri_float, scor_final)  # total = 24
    scoruri_float, scor_final = convertire_string_la_float_si_punere_in_lista("10.0 10.0 10.0")
    c4 = creeare_concurent(4, "Elena", scoruri_float, scor_final)  # total = 30
    concurenti = [c1, c2, c3, c4]

    functioneaza, scor_minim, mesaj = calcuealza_scor_minim_interval_participanti(concurenti, 0, 3)
    assert functioneaza is True
    assert mesaj == ""
    assert scor_minim == 6.0


def test_tipareste_concurentii_care_au_scorul_multiplu_de_numar():
    scoruri_float, scor_final = convertire_string_la_float_si_punere_in_lista("1.0 2.0 3.0")
    c1 = creeare_concurent(1, "Octavian", scoruri_float, scor_final)  # total = 6
    scoruri_float, scor_final = convertire_string_la_float_si_punere_in_lista("4.0 5.0 6.0")
    c2 = creeare_concurent(2, "Adriana", scoruri_float, scor_final)  # total = 15
    scoruri_float, scor_final = convertire_string_la_float_si_punere_in_lista("7.0 8.0 9.0")
    c3 = creeare_concurent(3, "Mihai", scoruri_float, scor_final)  # total = 24
    scoruri_float, scor_final = convertire_string_la_float_si_punere_in_lista("10.0 10.0 10.0")
    c4 = creeare_concurent(4, "Elena", scoruri_float, scor_final)  # total = 30
    concurenti = [c1, c2, c3, c4]

    lista, mesaj = tipareste_concurentii_care_au_scorul_multiplu_de_numar(concurenti, 10)
    assert lista == [c4]

    # Presupunem că 'inlocuieste_scorul...' actualizează și scorul final
    inlocuieste_scorul_de_la_un_concurent(concurenti, 4, 1, 5.0)

    lista, mesaj = tipareste_concurentii_care_au_scorul_multiplu_de_numar(concurenti, 10)
    assert lista == []


def toate_testele():
    test_creeaza_concurent()
    test_adaugare_concurent()
    test_inserare_scor_concurent()
    test_sterge_scorul_participant_dat()
    test_sterge_scor_pentru_interval_de_concurenti()
    test_inlocuieste_scorul_de_la_un_concurent()
    test_tiparire_concurenti_cu_scor_mai_mic_decat_scorul_dat()
    test_tipareste_scor_mai_mic_decat_cel_dat()
    test_tipareste_ordonat_dupa_scor()
    test_tipareste_concurentii_cu_scor_mai_mare_decat_scorul_dat_ordonati()
    test_calculeaza_media_scorurilor_interval_dat()
    test_calcuealza_scor_minim_interval_participanti()
    test_tipareste_concurentii_care_au_scorul_multiplu_de_numar()