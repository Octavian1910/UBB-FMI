#pragma once

#include <string>

using std::string;

class ValidatorException {
private:
    string msg;

public:
    ValidatorException(const string& msg) : msg{ msg } {}

    string getMessage() const {
        return msg;
    }
};