#include "Store.h"
#include <sstream>

Store::Store() {
    store.open(STORE_LOCATION + STORE_NAME, ios::in);
    if (store.is_open()) {
        string profileString;
        string name;
        string email;
        while (getline(store, profileString)) {
            istringstream profileStream(profileString);
            getline(profileStream, name, Profile::SEPARATOR);
            getline(profileStream, email, Profile::SEPARATOR);
            Profile loadedProfile(name, email);
            allProfiles.push_back(loadedProfile);
        }
    } else {
        store.clear();
    }
    store.close();
}

void Store::append(Profile& profile) {
    allProfiles.push_back(profile);
    isChanged = true;
}

Profile& Store::get(int id) {
    return allProfiles[id];
}

vector<Profile>& Store::getAll() {
    return allProfiles;
}

void Store::update(int id, Profile& profile) {
    allProfiles[id].setName(profile.getName());
    allProfiles[id].setEmail(profile.getEmail());
    isChanged = true;
}

void Store::remove(int id) {
    allProfiles.erase(allProfiles.begin() + id);
    isChanged = true;
}

int Store::size() {
    return allProfiles.size();
}

Store::~Store() {
    if (isChanged) {
        store.open(STORE_LOCATION + STORE_NAME, ios::out);
        for(Profile profile : allProfiles) {
            store << profile.toString() << endl;
        }
        store.close();
    }
}
