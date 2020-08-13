#include <string>
#include <cstdlib>
#include <iostream>
#include "Options/Options.h"
#include "Profile/Profile.h"
#include "Store/Store.h"
#include "help.h"

using namespace std;

const string WRONG_OPTS_MESSAGE("Wrong options!\nRun gsw --help for usage information");
const string EMPTY_NAME_EMAIL_MESSAGE("Name and email shouldn't be empty!\nRun gsw --help for usage information");
const string CURRENT_GIT_CMD("git config --get user.email");

void version();
void help();
void current();
void add(const string& name, const string& email);

int main(int argc, char **argv) {
    Options opts(argc, argv);
    if (opts.isExists("-h") || opts.isExists("--help")) {
        help();
    } else if (opts.isExists("-v") || opts.isExists("--version")) {
        version();
    } else if (opts.isExists("-c") || opts.isExists("--current")) {
        current();
    } else if (opts.isExists("-a") || opts.isExists("--add")) {
        add(opts.get("--name"), opts.get("--email"));
    } else {
        cout << WRONG_OPTS_MESSAGE;
    }
    return 0;
}

void version() {
    cout << VERSION;
}

void help() {
    cout << H_COMMON + "\n";
    cout << "Options:\n" << H_CURRENT + "\n" << H_VERSION + "\n" << H_HELP + "\n\n";
}

void current() {
    system(CURRENT_GIT_CMD.c_str());
}

void add(const string& name, const string& email) {
    if (name.empty() || email.empty()) {
        cout << EMPTY_NAME_EMAIL_MESSAGE;
        return;
    }
    Profile profile(name, email);
    Store store;
    store.append(profile);
}
