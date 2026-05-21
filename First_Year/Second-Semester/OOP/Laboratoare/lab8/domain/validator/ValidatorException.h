//
// Created by octav on 01.05.2026.
//

#ifndef LAB5_IT1_VALIDATOREXCEPTION_H
#define LAB5_IT1_VALIDATOREXCEPTION_H
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
     * :param msg: exception message
     */
    ValidatorException(string msg) : msg{std::move(msg)} {}

    /*
     * Gets exception message
     * :return: message
     */
    const string& getMessage() const
    {
        return msg;
    }
};

#endif //LAB5_IT1_VALIDATOREXCEPTION_H