#pragma once

#include <string>
using std::string;

class RepositoryException : std::exception
{
private:
    string msg;

public:
    RepositoryException(string msg) : msg{std::move(msg)} {}

    [[nodiscard]] string getMessage() const
    {
        return msg;
    }
};