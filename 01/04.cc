#include <iostream>
#include <regex>
#include <string>
#include <map>
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

int main() {
    const string s = "Hi He Lied Because Boron Could Not Oxidize Fluorine. New Nations Might Also Sign Peace Security Clause. Arthur King Can.";
    const vector<int>  condition{1, 5, 6, 7, 8, 9, 15, 16, 19};
    vector<string> ss;
    map<string, int> m;
    ss = split(s, ' ');

    int index = 1;
    string k;

    for (string s : ss) {
        bool result = any_of(condition.begin(), condition.end(), [index](int x) { return x == index; });
        if (result) {
            k = s.substr(0, 1);
            m[k] = index;
        } else {
            k = s.substr(0, 2);
            m[k] = index;
        }
        //std::cout << s << std::endl;
        for(auto itr = m.begin(); itr != m.end(); ++itr) {
            std::cout << "key = " << itr->first << ", val = " << itr->second << "\n";
        }
        index++;
    }
}