//
// Created by octav on 01.05.2026.
//

#ifndef LAB5_IT1_REPOSITORYEXCEPTION_H
#define LAB5_IT1_REPOSITORYEXCEPTION_H
#include <string>

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
     * :param msg: exception message
     */
    RepositoryException(string msg) : msg{std::move(msg)} {}

    /*
     * Gets exception message
     * :return: message
     */
    const string& getMessage() const
    {
        return msg;
    }
};

#endif //LAB5_IT1_REPOSITORYEXCEPTION_H