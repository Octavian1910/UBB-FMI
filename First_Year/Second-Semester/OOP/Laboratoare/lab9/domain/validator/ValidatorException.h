//
// Created by octav on 01.05.2026.
//

#pragma once

#include <string>

using std::string;

class ValidatorException
{
private:
    /*
     * msg: exception message
     */
    string msg;

public:
    /*
     * Creates validator exception
     * :param msg: exception message
     */
    ValidatorException(const string& msg) : msg{msg} {}

    /*
     * Gets exception message
     * :return: message
     */
    const string& getMessage() const
    {
        return msg;
    }
};