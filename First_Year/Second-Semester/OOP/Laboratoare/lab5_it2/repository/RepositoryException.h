//
// Created by octav on 01.05.2026.
//

#pragma once

#include <string>

using std::string;

class RepositoryException
{
private:
    /*
     * msg: exception message
     */
    string msg;

public:
    /*
     * Creates repository exception
     * :param msg: exception message
     */
    RepositoryException(const string& msg) : msg{msg} {}

    /*
     * Gets exception message
     * :return: message
     */
    const string& getMessage() const
    {
        return msg;
    }
};