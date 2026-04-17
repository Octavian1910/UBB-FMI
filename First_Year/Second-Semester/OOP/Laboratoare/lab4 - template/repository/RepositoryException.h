#ifndef LAB4_TEMPLATE_REPOISTORYEXCEPTION_H
#define LAB4_TEMPLATE_REPOISTORYEXCEPTION_H
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

#endif //LAB4_TEMPLATE_REPOISTORYEXCEPTION_H