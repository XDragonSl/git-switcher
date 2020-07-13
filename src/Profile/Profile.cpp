#include "Profile.h"

Profile::Profile(const string& name, const string& email) {
    this->name = name;
    this->email = email;
}

void Profile::setName(const string& name) {
    this->name = name;
}

void Profile::setEmail(const string& email) {
    this->email = email;
}

const string& Profile::getName() {
    return name;
}

const string& Profile::getEmail() {
    return email;
}

const string& Profile::toString() {
    static const string val(name + ";" + email);
    return val;
}
