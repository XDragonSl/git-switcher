#include <string>
#include <iostream>
#include "Options/Options.h"
#include "help.h"

using namespace std;

const string WRONG_OPTS_MESSAGE("Wrong options!\nRun gsw --help for usage information");
const string CURRENT_GIT_CMD("git config --get user.email");

void current();
void version();
void help();

int main(int argc, char **argv) {
    Options opts(argc, argv);
    if (opts.isExists("-c") || opts.isExists("--current")) {
        current();
    } else if (opts.isExists("-h") || opts.isExists("--help")) {
        help();
    } else if (opts.isExists("-v") || opts.isExists("--version")) {
        version();
    } else {
        cout << WRONG_OPTS_MESSAGE;
    }
    return 0;
}

void current() {
    system(CURRENT_GIT_CMD.c_str());
}

void version() {
    cout << VERSION;
}

void help() {
    cout << H_COMMON + "\n";
    cout << "Options:\n" << H_CURRENT + "\n" << H_VERSION + "\n" << H_HELP + "\n\n";
}
