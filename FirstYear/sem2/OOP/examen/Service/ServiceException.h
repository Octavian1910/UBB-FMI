#pragma once
#include <exception>
#include <string>
#include <utility>
using std::exception;
using std::string;

class ServiceException : public exception
{
private:
    string msg;

public:

    /*
     * Constructor pt ServiceException
     * pre ; string msg reprezentand eroare
     * post : se salveaza in msg eroarea
     */
    ServiceException(string msg): msg(std::move(msg)){}

    /*
     * Metoda returneaza un measaj reprezentand eroare
     * pre : -
     * post : un string reperzentand eroarea
     */
    const string& getMessage() const
    {
        return msg;
    }
};

