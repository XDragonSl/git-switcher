#pragma once

#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;


#ifdef _WIN32
    const string STORE_LOCATION(string(getenv("USERPROFILE")) + "\\");
#else
    const string STORE_LOCATION(string(getenv("HOME")) + "\\");
#endif

const string STORE_NAME(".gsw");

class Store {
    private:
        ofstream store;
    public:
        Store();
        ~Store();
};
