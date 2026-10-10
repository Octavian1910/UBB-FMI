//
// Created by octav on 01.04.2026.
//

#pragma once

#include <string>
#include <utility>

using std::string;

class ValidatorException
{
private:
    /*
     * error message
     */
    string msg;

public:
    /*
     * Creates exception
     * :param m: error message
     */
    ValidatorException(string m):msg{std::move(m)}{}

    /*
     * Gets error message
     * :return: message
     */
    string getMessage()
    {
        return msg;
    }
};
