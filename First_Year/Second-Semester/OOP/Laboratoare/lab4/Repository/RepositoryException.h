#ifndef LAB4_REPOISTORYEXCEPTION_H
#define LAB4_REPOISTORYEXCEPTION_H
#include <string>
using std::string;

class RepositoryException
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
    RepositoryException(string m):msg{m}{}

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