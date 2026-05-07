#pragma once
#include <string>
#include <utility>

using std::string;

class RepositoryException : public std::exception
{
private:
    /*
     * msg: exception message
     */
    string msg;

public:
    /*
     * Creates repository exception
     * :param msg: error message
     */
    RepositoryException(string msg)
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