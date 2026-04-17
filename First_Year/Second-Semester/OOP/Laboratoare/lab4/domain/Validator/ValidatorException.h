

#ifndef LAB4_VALIDATOREXCEPTION_H
#define LAB4_VALIDATOREXCEPTION_H
#include <utility>


class ValidatorException : public std::exception
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

#endif //LAB4_VALIDATOREXCEPTION_H