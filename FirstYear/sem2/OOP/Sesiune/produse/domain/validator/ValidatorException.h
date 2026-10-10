#pragma once

#include <string>
using std::string;

class ValidatorException : public std::exception
{
private:
    string msg;

public:
    ValidatorException(string msg) : msg{std::move(msg)} {}

    [[nodiscard]] string getMessage() const
    {
        return msg;
    }
};