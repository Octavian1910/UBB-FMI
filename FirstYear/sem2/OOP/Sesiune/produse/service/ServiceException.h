#pragma once

#include <string>
using std::string;

class ServiceException : std::exception
{
private:
    string msg;

public:
    ServiceException(string msg) : msg{std::move(msg)} {}

    [[nodiscard]] string getMessage() const
    {
        return msg;
    }
};