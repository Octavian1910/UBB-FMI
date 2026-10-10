#pragma once
#include <string>
using std::string;

class Melodie
{
private:
    int id;
    string title;
    string artist;
    int rank;

public:
    /*
     * Constructor pt melodie
     *  pre : id int , title string ,artist string , rank int
     *  post : se creeaza o melodie
     *
     */
    Melodie(int id,string title,string artist,int rank) : id(id),title(title),artist(artist),rank(rank){}

    /*
     * Ret un int reprezentand id ul melodiei
     * pre: -
     * post : un int reprezentand id ul melodie
     */
    int get_ID() const;

    /*
     * Ret un int care reprezinta rankul melodiei
     * pre : -
     * post : un int reprezentand rankul melodiei
     */
    int get_rank() const;

    /*
     * Returneaza titlul melodiei
     * pre : -
     * post : un string reprezentand titlul
     */
    const string& get_title() const;

    /*
     * Retrueneaza artistul melodiei
     * pre : -
     * post : un string reprezentand artisul
     */
    const string& get_artist() const;

    /*
     * Seter pt titlu
     * pre : un string care reprezinta noul titlu
     * post : se modifica obiectul
     */
    void set_title(const string& new_title);

    /*
     * Setter pt artist
     * pre : param new_artist un string
     * post :  se schimba artistul
     */
    void set_artist(const string& new_artist);

    /*
     * Setter pt rank
     * pre : param new_rank e un int
     * post : se seteaza noul rank
     */
    void set_rank(int new_rank);

};

