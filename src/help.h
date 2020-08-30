#pragma once

#include <string>

using namespace std;

namespace gsw_info {

    const string VERSION(".0");

    const string H_COMMON("Git Switcher\nVersion " + VERSION + "\n\ngsw <option>");
    const string H_VERSION("\t-v, --version:\t\t\t\t\t\t\tDisplay installed version");
    const string H_HELP("\t-h, --help:\t\t\t\t\t\t\tDisplay help");
    const string H_CURRENT("\t-c, --current:\t\t\t\t\t\t\tDisplay current user email");
    const string H_LIST("\t-l, --list:\t\t\t\t\t\t\tDisplay list of all user profiles");
    const string H_ADD("\t-a, --add \n\t\t--name <name> --email <email>:\t\t\t\tAdd new user profile");
    const string H_UPDATE("\t-u, --update \n\t\t--number <number> --name <name> --email <email>:\tUpdate existing user profile");
    const string H_SWAP("\t-s, --switch \n\t\t<number>:\t\t\t\t\t\tSwitch user profile");
    const string H_REMOVE("\t-r, --remove \n\t\t<number>:\t\t\t\t\t\tRemove user profile");

}
