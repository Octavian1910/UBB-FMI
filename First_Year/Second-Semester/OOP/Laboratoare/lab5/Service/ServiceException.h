#ifndef LAB4_SERVICEEXCEPTION_H
#define LAB4_SERVICEEXCEPTION_H

#include <string>
#include <utility>
#include <exception>

using std::string;

class ServiceException : public std::exception
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
    explicit ServiceException(string m)
        : msg{ std::move(m) }
    {
    }

    /*
     * Gets error message
     * :return: message
     */
    string getMessage() const
    {
        return msg;
    }

    /*
     * Standard exception message
     */
    const char* what() const noexcept override
    {
        return msg.c_str();
    }
};

#endif //LAB4_SERVICEEXCEPTION_H