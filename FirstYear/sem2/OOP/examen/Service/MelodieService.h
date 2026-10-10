#pragma once

#include "../repository/MelodieRepository.h"
#include "../domain/validator/ValidatorMelodie.h"

class MelodieService
{
private:
    MelodieRepository& repo;
    ValidatorMelodie& validator;

public:
    /*
     * Constructor pt Melodie Service
     * pre : repo este un MelodieRepository ; validator este un ValidatorMelodie
     * post : se initializeaza clasa Service
     */
    MelodieService(MelodieRepository& repo,ValidatorMelodie& validator):repo(repo),validator(validator){}


    /*
     * Returneaza vectorul gata sortat cu elementele din repo
     */
    vector<Melodie> getAllSorted() const;

    /*
     * Initializeaza cautarea in repo dupa id
     * pre : un int reprezentand id ul
     * post : returneaza un obiect de tip Melodie daca se gaseste
     */
    const Melodie& find(int id) const;

    /*
     * Metoda initializeaza update catre repo
     * pre : id int , string title ,int rank
     * post : se da update daca exista
     */
    void update(int id,string title,int rank);

    /*
     * Metooda initializeaza stergearea dupa id doar daca artistul are mai mult de o piesa
     * pre : id
     * post : stergerea s a efectuat
     */
    void remove(int id);

    /*
     * Metoda returneaza cate dintre Melodii au acelasi rank dupa parametrul rank
     * pre : rank un intr
     * post : un int reprezentand cate melodii din repo au acelasi rank
     */
    int countRank(int rank) const;
};