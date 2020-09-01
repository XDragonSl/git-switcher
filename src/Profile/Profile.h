#pragma once

#include <string>

using namespace std;

class Profile {
    private:
        string name;
        string email;
    public:
        Profile(const string& name, const string& email);
        void setName(const string& name);
        void setEmail(const string& email);
        const string& getName();
        const string& getEmail();
        const string toString();
        static const char SEPARATOR = ';';
};
