#include <fstream>
#include <iostream>
#include <regex>
#include <string>
using namespace std;


int main(int argc, char *argv[]) {
    ifstream ifs(argv[1]);
    string s;

    if (ifs.fail()) {
        cerr << "Failed to open file. " << argv[1] << endl;
        return -1;
    }

    while (getline(ifs, s)) {
        s = regex_replace(s, regex("\t"), " ");
        cout << s << endl;
    }
}