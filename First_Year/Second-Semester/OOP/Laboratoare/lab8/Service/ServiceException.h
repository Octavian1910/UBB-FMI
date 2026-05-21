//
// Created by octav on 01.05.2026.
//

#ifndef LAB5_IT1_SERVICEEXCEPTION_H
#define LAB5_IT1_SERVICEEXCEPTION_H
#include <string>

using std::string;

class ServiceException
{
private:
    /*
     * msg: exception message
     */
    string msg;

public:
    /*
     * Creates service exception
     * :param msg: exception message
     */
    ServiceException(const string& msg) : msg{msg} {}

    /*
     * Gets exception message
     * :return: message
     */
    const string& getMessage() const
    {
        return msg;
    }
};

#endif //LAB5_IT1_SERVICEEXCEPTION_H