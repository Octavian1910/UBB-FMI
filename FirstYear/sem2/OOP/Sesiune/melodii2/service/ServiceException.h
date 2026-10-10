#pragma once

#include <string>

using std::string;

class ServiceException {
private:
    string msg;

public:
    ServiceException(const string& msg): msg{ msg } { }

    string getMessage() const {
        return msg;
    }
};