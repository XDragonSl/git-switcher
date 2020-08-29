#include <string>
#include <cstdlib>
#include <iostream>
#include "Options/Options.h"
#include "Profile/Profile.h"
#include "Store/Store.h"
#include "help.h"

using namespace std;

const string RUN_HELP_MESSAGE("Run gsw --help for usage information");
const string WRONG_OPTS_MESSAGE("Wrong options!");
const string WRONG_SWITCH_PARAM_MESSAGE("Wrong switch parameter!");
const string NONEXISTENT_INDEX_MESSAGE("Wrong profile index!");
const string EMPTY_NAME_EMAIL_MESSAGE("Name and email shouldn't be empty!");
const string CURRENT_GIT_CMD("git config --get user.email");
const string SWAP_NAME_GIT_CMD("git config --global --replace-all user.name ");
const string SWAP_EMAIL_GIT_CMD("git config --global --replace-all user.email ");
const string QUOTE("\"");

void version();
void help();
void current();
void add(const string& name, const string& email);
void swap(int number);

int main(int argc, char **argv) {
    setlocale(LC_ALL, "Russian");
    Options opts(argc, argv);
    if (opts.isExists("-h") || opts.isExists("--help")) {
        help();
    } else if (opts.isExists("-v") || opts.isExists("--version")) {
        version();
    } else if (opts.isExists("-c") || opts.isExists("--current")) {
        current();
    } else if (opts.isExists("-a") || opts.isExists("--add")) {
        add(opts.get("--name"), opts.get("--email"));
    } else if (opts.isExists("-s") || opts.isExists("--switch")) {
        string shortParam(opts.get("-s"));
        string longParam(opts.get("--switch"));
        try {
            if (!shortParam.empty()) {
                swap(stoi(shortParam));
            } else if (!longParam.empty()) {
                swap(stoi(longParam));
            } else {
                throw invalid_argument(WRONG_SWITCH_PARAM_MESSAGE.c_str());
            }
        } catch(const exception& e) {
            cout << WRONG_SWITCH_PARAM_MESSAGE << endl;
            cout << RUN_HELP_MESSAGE;
        }
    } else {
        cout << WRONG_OPTS_MESSAGE << endl;
        cout << RUN_HELP_MESSAGE;
    }
    return 0;
}

void version() {
    cout << VERSION;
}

void help() {
    cout << H_COMMON << endl;
    cout << "Options:" << endl;
    cout << H_VERSION << endl;
    cout << H_HELP << endl;
    cout << H_CURRENT << endl;
    cout << H_ADD << endl;
    cout << H_SWAP << endl;
    cout << endl;
}

void current() {
    system(CURRENT_GIT_CMD.c_str());
}

void add(const string& name, const string& email) {
    if (name.empty() || email.empty()) {
        cout << EMPTY_NAME_EMAIL_MESSAGE << endl;
        cout << RUN_HELP_MESSAGE;
        return;
    }
    Profile profile(name, email);
    Store store;
    store.append(profile);
}

void swap(int number) {
    Store store;
    if (number <= 0 || number > store.size()) {
        cout << NONEXISTENT_INDEX_MESSAGE << endl;
        cout << RUN_HELP_MESSAGE;
        return;
    }
    Profile chosen = store.get(number - 1);
    string swapName(SWAP_NAME_GIT_CMD + QUOTE + chosen.getName() + QUOTE);
    string swapEmail(SWAP_EMAIL_GIT_CMD + QUOTE + chosen.getEmail() + QUOTE);
    system(swapName.c_str());
    system(swapEmail.c_str());
}
