#include <fstream>
#include <iostream>
#include <regex>
#include <string>
#include <vector>
using namespace std;

vector<string> split(const string &s, const char delim) {
    vector<string> elems;
    string item;
    for (char ch: s) {
        if (ch == delim) { // 区切り文字が来たらvectorに入れる
            item = regex_replace(item, regex("[^a-zA-Z0-9]+"), "");
            if (!item.empty()) elems.push_back(item);
            item.clear();
        }
        else { // 区切り文字が来るまではitemに溜め込む
            item += ch;
        }
    }
    item = regex_replace(item, regex("[^a-zA-Z0-9]+"), "");
    if (!item.empty()) elems.push_back(item);
    return elems;
}

int main(int argc, char *argv[]) {
    ifstream ifs(argv[1]);
    ofstream outputfile1("col1.txt");
    ofstream outputfile2("col2.txt");
    string s;
    vector<string> ss;
    
    if (ifs.fail()) {
        cerr << "Failed to open file. " << argv[1] <<endl;
        return -1;
    }

    while (getline(ifs, s)) {
        ss = split(s, '\t');
        outputfile1 << ss[0] << endl;
        outputfile2 << ss[1] << endl;
    }
    outputfile1.close();
    outputfile2.close();
}