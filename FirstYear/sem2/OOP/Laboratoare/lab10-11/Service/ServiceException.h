#pragma once
#include <string>
#include <utility>

using std::string;

class ServiceException : public std::exception
{
private:
    /*
     * msg: exception message
     */
    string msg;

public:
    /*
     * Creates service exception
     * :param msg: error message
     */
    ServiceException(string msg)
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