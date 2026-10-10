#pragma once

#include <exception>
#include <string>
using std::string;
class RepositoryException : std::exception
{
private:
    string msg;

public:
    /*
     * Constructor
     * pre : param msg este un string
     * post : -
     */
    RepositoryException(string msg) : msg(msg){}

    /*
     * Metoda returneaza mesajul din exceptie
     */
    const string& getMessage() const
    {
        return msg;
    };
};

