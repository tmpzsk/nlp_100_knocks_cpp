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

vector<string> n_gram(const string &s, const int n) {
    vector<string> elems;
    for (int i = 0; i <= s.size() - n; i++) {
        string k = s.substr(i, n);
        elems.push_back(k);
    }
    return elems;
}

vector<vector<string> > n_gram(const vector<string> &s, const int n) {
    vector<string> elem;
    vector<vector<string> > elems;
    for (int i = 0; i <= s.size() - n; i++) {
        for (int j = i; j < i + n; j++) {
            cout << s[j] << endl;
            elem.push_back(s[j]);
        }
        elems.push_back(elem);
        elem.clear();
    }
    return elems;
}

int main() {
    const string s = "I am an NLPer";
    const vector<string> s_list = split(s, ' ');
    vector<string> ss;
    vector<vector<string> > sss;
    // string
    ss = n_gram(s, 2);
    for (string s : ss) {
        cout << s << endl;
    }
    // list
    sss = n_gram(s_list, 2);
    for (vector<string> ss: sss) {
        cout << "[";
        for (string s : ss) {
            cout << "'" << s << "'";
        }
        cout << "]" << endl;
    }
}