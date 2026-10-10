#pragma once
#include <exception>
#include <string>
#include <utility>

using std::string;

class ValidatorException : public std::exception
{
private:
    /*
     * msg: exception message
     */
    string msg;

public:
    /*
     * Creates validator exception
     * :param msg: error message
     */
    ValidatorException(string msg)
        : msg{std::move(msg)} {}

    /*
     * Gets exception message
     * :return: message
     */
    [[nodiscard]] const string& getMessage() const
    {
        return msg;
    }
};