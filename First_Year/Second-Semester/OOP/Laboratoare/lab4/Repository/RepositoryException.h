#ifndef LAB4_REPOISTORYEXCEPTION_H
#define LAB4_REPOISTORYEXCEPTION_H
#include <string>
#include <utility>
using std::string;

class RepositoryException : public std::exception
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
    RepositoryException(string m):msg{std::move(m)}{}

    /*
     * Gets error message
     * :return: message
     */
    string getMessage()
    {
        return msg;
    }
};

#endif //LAB4_REPOISTORYEXCEPTION_H