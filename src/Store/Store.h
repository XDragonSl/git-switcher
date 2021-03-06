#pragma once

#include <cstdlib>
#include <string>
#include <fstream>
#include <vector>
#include "../Profile/Profile.h"

using namespace std;

#ifdef _WIN32
    const string STORE_LOCATION(string(getenv("USERPROFILE")) + "\\");
#else
    const string STORE_LOCATION(string(getenv("HOME")) + "/");
#endif

const string STORE_NAME(".gsw");

class Store {
    private:
        fstream store;
        vector<Profile> allProfiles;
        bool isChanged = false;
    public:
        Store();
        void append(Profile& profile);
        Profile& get(int id);
        vector<Profile>& getAll();
        void update(int id, Profile& profile);
        void remove(int id);
        int size();
        ~Store();
};
