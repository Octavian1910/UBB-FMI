//
// Created by octav on 21.05.2026.
//

#ifndef RADATION_VALIDATOREXCEPTION_H
#define RADATION_VALIDATOREXCEPTION_H
#include <exception>
#include <string>


class ValidatorException:public std::exception
{
private:
    std::string msg;
    public:
    ValidatorException(std::string msg):msg{msg}{}

    const std::string& getMessage() const
    {
        return msg;
    };

};


#endif //RADATION_VALIDATOREXCEPTION_H