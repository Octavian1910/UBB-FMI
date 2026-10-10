#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
 
#include "../domain/medicament.h"
#include "../domain/validators/validator.h"
#include "../repository/repository.h"
#include "../service/service.h"
 
 
void testCreeazaMedicament()
{
    Medicament m = creeazaMedicament(1, "Paracetamol", 500, 10);
 
    assert(m.cod == 1);
    assert(strcmp(m.nume, "Paracetamol") == 0);
    assert(m.concentratie == 500);
    assert(m.cantitate == 10);
 
    assert(m.cod == get_cod(&m));
    assert(strcmp(m.nume, get_nume(&m)) == 0);
    assert(m.concentratie == get_concentratie(&m));
    assert(m.cantitate == get_cantitate(&m));
 
    set_nume(&m, "Octa");
    assert(strcmp("Octa", get_nume(&m)) == 0);
    set_concentratie(&m, 100);
    assert(100 == get_concentratie(&m));
 
    set_cantitate(&m, 15);
    assert(15 == get_cantitate(&m));
 
    set_cod(&m, 100);
    assert(get_cod(&m) == 100);
}
 
void testeValidatorMedicament()
{
    Medicament m_ok = creeazaMedicament(1, "Paracetamol", 500, 10);
    assert(valideazaMedicament(&m_ok) == 0);
 
    Medicament m_cod_gresit = creeazaMedicament(-5, "Parasinus", 300, 5);
    assert(valideazaMedicament(&m_cod_gresit) == 1);
 
    Medicament m_nume_gresit = creeazaMedicament(2, "", 300, 5);
    assert(valideazaMedicament(&m_nume_gresit) == 2);
 
    Medicament m_concentratie_gresita = creeazaMedicament(2, "Paracetamol", -150, 5);
    assert(valideazaMedicament(&m_concentratie_gresita) == 3);
 
    Medicament m_cantitate_gresita = creeazaMedicament(2, "Paracetamol", 150, -15);
    assert(valideazaMedicament(&m_cantitate_gresita) == 4);
}
 
void testRepositoryMedicamente()
{
    RepoFarmacie repo = creeazaRepo();
 
    Medicament m1 = creeazaMedicament(1, "Paracetamol", 500, 10);
    Medicament m2 = creeazaMedicament(2, "Parasinus", 300, 5);
    Medicament m3 = creeazaMedicament(3, "Aspirina", 250, 12);
 
    adauga_repo(&repo, m1);
    adauga_repo(&repo, m2);
    adauga_repo(&repo, m3);
 
    assert(get_lungime_repo(&repo) == 3);
 
    Medicament* aspirina = cauta_medicament_repo(&repo, 3);
    assert(aspirina != NULL);
    assert(strcmp(get_nume(aspirina), "Aspirina") == 0);
 
    Medicament** lista = get_all_repo(&repo);
    assert(strcmp(get_nume(lista[0]), "Paracetamol") == 0);
    assert(strcmp(get_nume(lista[1]), "Parasinus") == 0);
    assert(strcmp(get_nume(lista[2]), "Aspirina") == 0);
    free(lista);
}
 
void testRepositoryActualizeazaMedicamente()
{
    RepoFarmacie repo = creeazaRepo();
 
    Medicament m1 = creeazaMedicament(1, "Paracetamol", 500, 10);
    Medicament m2 = creeazaMedicament(1, "Parasinus", 300, 5);
    Medicament m3 = creeazaMedicament(3, "Aspirina", 250, 12);
 
    adauga_repo(&repo, m1);
 
    int rez = actualizeaza_element_repo(&repo, m2);
    assert(rez == 0);
 
    Medicament* elem = cauta_medicament_repo(&repo, 1);
    assert(strcmp(get_nume(elem), "Parasinus") == 0);
    assert(get_concentratie(elem) == 300);
    assert(get_cantitate(elem) == 10); // cantitatea nu se schimba la actualizare
 
    int rez2 = actualizeaza_element_repo(&repo, m3);
    assert(rez2 == -1); // nu exista cod 3
}
 
void testStergeStocRepoMedicament()
{
    RepoFarmacie repo = creeazaRepo();
 
    Medicament m1 = creeazaMedicament(1, "Paracetamol", 500, 10);
    Medicament m2 = creeazaMedicament(2, "Parasinus", 300, 5);
    Medicament m3 = creeazaMedicament(3, "Aspirina", 250, 12);
 
    adauga_repo(&repo, m1);
    adauga_repo(&repo, m2);
    adauga_repo(&repo, m3);
 
    assert(repo.lungime == 3);
 
    sterge_repo(&repo, 1);
    Medicament* elem = cauta_medicament_repo(&repo, 1);
    assert(get_cantitate(elem) == 0);
 
    assert(sterge_repo(&repo, 150) == -1);
}
 
void testServiceMedicamente()
{
    RepoFarmacie repo = creeazaRepo();
    ServiceFarmacie s = creeaza_service_farmacie(&repo, NULL);
 
    assert(nr_medicamente_service(&s) == 0);
 
    adaugaService(&s, 1, "Paracetamol", 500, 10);
    adaugaService(&s, 2, "Parasinus", 300, 5);
    adaugaService(&s, 3, "Aspirina", 250, 12);
 
    assert(adaugaService(&s, -50, "Aspirina", 250, 12) == 1);
    assert(nr_medicamente_service(&s) == 3);
 
    adaugaService(&s, 1, "Paracetamol", 500, 150); // actualizeaza cantitatea
    assert(nr_medicamente_service(&s) == 3);
 
    Medicament* elem = cauta_medicament_service(&s, 1);
    assert(get_cantitate(elem) == 150);
}
 
void testServiceActualizareMedicament()
{
    RepoFarmacie repo = creeazaRepo();
    ServiceFarmacie s = creeaza_service_farmacie(&repo, NULL);
 
    adaugaService(&s, 1, "Paracetamol", 500, 10);
    adaugaService(&s, 2, "Parasinus", 300, 5);
    adaugaService(&s, 3, "Aspirina", 250, 12);
 
    assert(nr_medicamente_service(&s) == 3);
    assert(actualizeazaService(&s, 1, "Octa", 100) == 0);
 
    Medicament* temp = cauta_medicament_repo(&repo, 1);
    assert(strcmp(get_nume(temp), "Octa") == 0);
    assert(get_concentratie(temp) == 100);
 
    assert(actualizeazaService(&s, -50, "Aspirina", 12) == 1);
}
 
void testStergeStocServiceMedicament()
{
    RepoFarmacie repo = creeazaRepo();
    ServiceFarmacie s = creeaza_service_farmacie(&repo, NULL);
 
    adaugaService(&s, 1, "Paracetamol", 500, 10);
    adaugaService(&s, 2, "Parasinus", 300, 5);
    adaugaService(&s, 3, "Aspirina", 250, 12);
 
    sterge_service(&s, 1);
    Medicament* elem = cauta_medicament_service(&s, 1);
    assert(get_cantitate(elem) == 0);
}
 
void testSorteazaServiceMedicamente()
{
    RepoFarmacie repo = creeazaRepo();
    ServiceFarmacie s = creeaza_service_farmacie(&repo, NULL);
 
    adaugaService(&s, 1, "Zyx", 100, 50);
    adaugaService(&s, 2, "Abc", 200, 10);
    adaugaService(&s, 3, "Mno", 150, 30);
    adaugaService(&s, 4, "Mno", 400, 35);
 
    int nr = 0;
    Medicament** lista;
 
    // 1. Sortare dupa Nume - Crescator
    lista = sortareMedicamente(&s, 1, 1, &nr);
    assert(nr == 4);
    assert(strcmp(get_nume(lista[0]), "Abc") == 0);
    assert(strcmp(get_nume(lista[1]), "Mno") == 0);
    assert(strcmp(get_nume(lista[2]), "Mno") == 0);
    assert(strcmp(get_nume(lista[3]), "Zyx") == 0);
    free(lista);
 
    // 2. Sortare dupa Nume - Descrescator
    lista = sortareMedicamente(&s, 1, 0, &nr);
    assert(strcmp(get_nume(lista[0]), "Zyx") == 0);
    assert(strcmp(get_nume(lista[1]), "Mno") == 0);
    assert(strcmp(get_nume(lista[2]), "Mno") == 0);
    assert(strcmp(get_nume(lista[3]), "Abc") == 0);
    free(lista);
 
    // 3. Sortare dupa Cantitate - Crescator
    lista = sortareMedicamente(&s, 2, 1, &nr);
    assert(get_cantitate(lista[0]) == 10);
    assert(get_cantitate(lista[1]) == 30);
    assert(get_cantitate(lista[2]) == 35);
    assert(get_cantitate(lista[3]) == 50);
    free(lista);
 
    // 4. Sortare dupa Cantitate - Descrescator
    lista = sortareMedicamente(&s, 2, 0, &nr);
    assert(get_cantitate(lista[0]) == 50);
    assert(get_cantitate(lista[1]) == 35);
    assert(get_cantitate(lista[2]) == 30);
    assert(get_cantitate(lista[3]) == 10);
    free(lista);
}
 
void testFiltreazaServiceMedicamente()
{
    RepoFarmacie repo = creeazaRepo();
    ServiceFarmacie s = creeaza_service_farmacie(&repo, NULL);
 
    adaugaService(&s, 1, "MemoPLus", 100, 50);
    adaugaService(&s, 2, "Murofen", 200, 10);
    adaugaService(&s, 3, "Paracetamol", 150, 30);
 
    int nr = 0;
    Medicament** lista;
 
    // 1. Filtrare cantitate mai mica decat valoare data
    char valoare[50] = "31";
    lista = filtrareMedicamente(&s, 1, valoare, &nr);
    assert(nr == 2);
    assert(strcmp(get_nume(lista[0]), "Murofen") == 0);
    assert(strcmp(get_nume(lista[1]), "Paracetamol") == 0);
    free(lista);
 
    // 2. Filtrare dupa prima litera
    strcpy(valoare, "m");
    lista = filtrareMedicamente(&s, 2, valoare, &nr);
    assert(nr == 2);
    assert(strcmp(get_nume(lista[0]), "MemoPLus") == 0);
    assert(strcmp(get_nume(lista[1]), "Murofen") == 0);
    free(lista);
}
 
void ruleazaToateTestele()
{
    testCreeazaMedicament();
    testeValidatorMedicament();
 
    // REPO
    testRepositoryMedicamente();
    testRepositoryActualizeazaMedicamente();
    testStergeStocRepoMedicament();
 
    // SERVICE
    testServiceMedicamente();
    testServiceActualizareMedicament();
    testStergeStocServiceMedicament();
    testSorteazaServiceMedicamente();
    testFiltreazaServiceMedicamente();
 
    printf("Testele au fost rulate cu succes!\n");
}