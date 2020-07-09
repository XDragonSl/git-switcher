#ifndef OPTIONS_H_
#define OPTIONS_H_

#include <string>
#include <vector>

using namespace std;

class Options {
    private:
        vector<string> tokens;
    public:
        Options (int &argc, char **argv);
        const string& get(const string &option);
        bool isExists(const string &option);
};

#endif
