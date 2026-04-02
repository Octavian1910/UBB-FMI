//
// Created by octav on 01.04.2026.
//

#ifndef LAB4_VALIDATOREXCEPTION_H
#define LAB4_VALIDATOREXCEPTION_H

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
    ValidatorException(string m):msg{m}{}

    /*
     * Gets error message
     * :return: message
     */
    string getMessage()
    {
        return msg;
    }
};

#endif //LAB4_VALIDATOREXCEPTION_H