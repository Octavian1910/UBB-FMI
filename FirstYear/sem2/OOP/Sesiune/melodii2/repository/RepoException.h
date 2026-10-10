#pragma once

#include <string>

using std::string;

class RepoException {
private:
    string msg;

public:
    RepoException(const string& msg) : msg{ msg } {}

    string getMessage() const
    {
        return msg;
    }
};