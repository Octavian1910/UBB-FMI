#pragma once
#include <exception>
#include <string>
#include <utility>

using std::string;

class ValidatorException : public std::exception
{
private:
    string msg;

public:
    /*Constructor
     * pre : msg string
     * post : -
     */
    ValidatorException(const string& msg) : msg(msg){};

    /*Metoda returneaza mesajul
     * pre : -
     * post : string cu msg
     *
     */
    const string& getMessage() const
    {
        return msg;
    }
};

