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

Store::~Store() {
    if (isChanged) {
        store.open(STORE_LOCATION + STORE_NAME, ios::out);
        for(Profile profile : allProfiles) {
            store << profile.toString() << endl;
        }
        store.close();
    }
}
