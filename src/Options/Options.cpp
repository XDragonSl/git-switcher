#include "Options.h"
#include <algorithm>

Options::Options(int &argc, char **argv) {
    for (int i=1; i < argc; ++i) {
        this->tokens.push_back(string(argv[i]));
    }
}

const string& Options::get(const string &option) {
    vector<string>::const_iterator itr;
    itr = find(this->tokens.begin(), this->tokens.end(), option);
    if (itr != this->tokens.end() && ++itr != this->tokens.end()){
        return *itr;
    }
    static const string empty_string("");
    return empty_string;
}

bool Options::isExists(const string &option) {
    return find(this->tokens.begin(), this->tokens.end(), option) != this->tokens.end();
}
