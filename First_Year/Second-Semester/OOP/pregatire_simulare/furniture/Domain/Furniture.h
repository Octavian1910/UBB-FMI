//
// Created by octav on 22.05.2026.
//

#ifndef FURNITURE_FURNITURE_H
#define FURNITURE_FURNITURE_H
#include <string>
using std::string;


class Furniture
{
private:
    int id;
    string type;
    int nr_pieces;
    int time;
public:
    Furniture(int id,string type,int nr_pieces,int time):id(id),type(type),nr_pieces(nr_pieces),time(time){}
    int get_id() const;
    int get_nr_pieces() const;
    int get_time() const;
    const string& get_type() const;
};


#endif //FURNITURE_FURNITURE_H