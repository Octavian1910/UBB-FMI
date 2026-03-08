// teste.c
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include "../domain/medicament.h"
#include "../domain/validators/validator.h"
#include "../repository/repository.h"
#include "../service/service.h"


void testCreeazaMedicament() {
    Medicament* m = creeazaMedicament(1, "Paracetamol", 500, 10);

    assert(m->cod == 1);
    assert(strcmp(m->nume, "Paracetamol") == 0);
    assert(m->concentratie == 500);
    assert(m->cantitate == 10);

    assert(m->cod == get_cod(m));
    assert(strcmp(m->nume,get_nume(m)) == 0);
    assert(m->concentratie == get_concentratie(m));
    assert(m->cantitate == get_cantitate(m));


    set_nume(m,"Octa");
    assert(strcmp("Octa",get_nume(m)) == 0);
    set_concentratie(m,100);
    assert(100 == get_concentratie(m));

    set_cantitate(m,15);
    assert(15 == get_cantitate(m));

    distrugeMedicament(m);
}

void testeValidatorMedicament()
{
    Medicament* m_ok = creeazaMedicament(1, "Paracetamol", 500, 10);
    assert(valideazaMedicament(m_ok) == 0);
    Medicament* m_cod_gresit = creeazaMedicament(-5, "Parasinus", 300, 5);
    assert(valideazaMedicament(m_cod_gresit) == 1);
    Medicament* m_nume_gresit = creeazaMedicament(2, "", 300, 5);
    assert(valideazaMedicament(m_nume_gresit) == 2);
    Medicament* m_concentratie_gresita = creeazaMedicament(2, "Paracetamol", -150, 5);
    assert(valideazaMedicament(m_concentratie_gresita) == 3);
    Medicament* m_cantitate_gresita = creeazaMedicament(2, "Paracetamol", 150, -15);
    assert(valideazaMedicament(m_cantitate_gresita) == 4);

    distrugeMedicament(m_ok);
    distrugeMedicament(m_cod_gresit);
    distrugeMedicament(m_nume_gresit);
    distrugeMedicament(m_concentratie_gresita);
    distrugeMedicament(m_cantitate_gresita);

}

void testRepositoryMedicamente()
{
    RepoFarmacie* repo_farmacie = creeazaRepo();
    Medicament* m1 = creeazaMedicament(1, "Paracetamol", 500, 10);
    Medicament* m2 = creeazaMedicament(2, "Parasinus", 300, 5);

    Medicament* m3 = creeazaMedicament(3, "Aspirina", 250, 12);


    adauga_repo(repo_farmacie,m1);
    adauga_repo(repo_farmacie,m2);
    assert(repo_farmacie->capacitate == 2);
    adauga_repo(repo_farmacie,m3);
    assert(repo_farmacie->lungime == 3);
    assert(repo_farmacie->capacitate == 4);

    Medicament *aspirina = cauta_medicament_repo(repo_farmacie,3);
    assert(aspirina == m3);
    distrugeRepo(repo_farmacie);
}

void testServiceMedicamente()
{
    RepoFarmacie* repo = creeazaRepo();
    ValidatorMedicament* validator = NULL;
    ServiceFarmacie* s = creeaza_service_farmacie(repo,validator);
    assert(nr_medicamente_service(s) == 0);
    adaugaService(s,1, "Paracetamol", 500, 10);
    adaugaService(s,2, "Parasinus", 300, 5);
    adaugaService(s,3, "Aspirina", 250, 12);
    assert(nr_medicamente_service(s) == 3);
    adaugaService(s,1, "Paracetamol", 500, 150);
    assert(nr_medicamente_service(s) == 3);
    Medicament *elem = cauta_medicament_service(s,1);
    assert(get_cantitate(elem) == 150);
    distruge_service_farmacie(s);


}
void testRepositoryActualizeazaMedicamente()
{
    RepoFarmacie* repo_farmacie = creeazaRepo();
    Medicament* m1 = creeazaMedicament(1, "Paracetamol", 500, 10);
    Medicament* m2 = creeazaMedicament(1, "Parasinus", 300, 5);
    Medicament* m3 = creeazaMedicament(3, "Aspirina", 250, 12);
    adauga_repo(repo_farmacie,m1);
    int rez = actualizeaza_element_repo(repo_farmacie,m2);
    m2 = creeazaMedicament(1, "Parasinus", 300, 5); ///f imp se distruge m2 si trb sa in realoci
    assert(rez == 0);
    Medicament* elem = cauta_medicament_repo(repo_farmacie,get_cod(m1));
    assert(strcmp(get_nume(elem),get_nume(m2)) == 0);
    assert(get_concentratie(m2) == get_concentratie(elem));
    assert(get_cantitate(m2) != get_cantitate(elem));
    int rez2 = actualizeaza_element_repo(repo_farmacie,m3);
    assert(rez2 == -1);
    distrugeRepo(repo_farmacie);

}

void testServiceActualizareMedicament()
{
    RepoFarmacie* repo = creeazaRepo();
    ValidatorMedicament* validator = NULL;
    ServiceFarmacie* s = creeaza_service_farmacie(repo,validator);
    assert(nr_medicamente_service(s) == 0);
    adaugaService(s,1, "Paracetamol", 500, 10);
    adaugaService(s,2, "Parasinus", 300, 5);
    adaugaService(s,3, "Aspirina", 250, 12);
    assert(nr_medicamente_service(s) == 3);
    actualizeazaService(s,1,"Octa",100);
    Medicament* temp = cauta_medicament_repo(repo,1);
    assert(strcmp(get_nume(temp),"Octa") == 0);
    assert(get_concentratie(temp) == 100);
    distruge_service_farmacie(s);
}

void testStergeStocRepoMedicament()
{
    RepoFarmacie* repo_farmacie = creeazaRepo();
    Medicament* m1 = creeazaMedicament(1, "Paracetamol", 500, 10);
    Medicament* m2 = creeazaMedicament(2, "Parasinus", 300, 5);

    Medicament* m3 = creeazaMedicament(3, "Aspirina", 250, 12);


    adauga_repo(repo_farmacie,m1);
    adauga_repo(repo_farmacie,m2);
    adauga_repo(repo_farmacie,m3);
    assert(repo_farmacie->lungime == 3);
    assert(get_cantitate(m1) == 10);
    sterge_repo(repo_farmacie,1);
    Medicament* elem = cauta_medicament_repo(repo_farmacie,1);
    assert(get_cantitate(elem) == 0);
    distrugeRepo(repo_farmacie);
}

void testStergeStocServiceMedicament()
{
    RepoFarmacie* repo = creeazaRepo();
    ValidatorMedicament* validator = NULL;
    ServiceFarmacie* s = creeaza_service_farmacie(repo,validator);
    adaugaService(s,1, "Paracetamol", 500, 10);
    adaugaService(s,2, "Parasinus", 300, 5);
    adaugaService(s,3, "Aspirina", 250, 12);
    sterge_service(s,1);
    Medicament* elem = cauta_medicament_service(s,1);
    assert(get_cantitate(elem) == 0);
    distruge_service_farmacie(s);
}

void ruleazaToateTestele()
{
    testCreeazaMedicament();
    testeValidatorMedicament();

    //REPO
    testRepositoryMedicamente();
    testRepositoryActualizeazaMedicamente();
    testStergeStocRepoMedicament();

    //SERVICE
    testServiceMedicamente();
    testServiceActualizareMedicament();
    testStergeStocServiceMedicament();

    printf("Testele au fost rulate cu succes!\n");
}




