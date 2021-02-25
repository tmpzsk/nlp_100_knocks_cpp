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

vector<int> split_size(const string &s, char delim) {
    vector<int> elem_sizes;
    string item;
    for (char ch: s) {
        if (ch == delim) { // 区切り文字が来たらvectorに入れる
            item = regex_replace(item, regex("[^a-zA-Z0-9]+"), "");
            if (!item.empty()) elem_sizes.push_back(item.size());
            item.clear();
        }
        else { // 区切り文字が来るまではitemに溜め込む
            item += ch;
        }
    }
    item = regex_replace(item, regex("[^a-zA-Z0-9]+"), "");
    if (!item.empty()) elem_sizes.push_back(item.size());
    return elem_sizes;
}

int main() {
    const string s = "Now I need a drink, alcoholic of course, after the heavy lectures involving quantum mechanics.";
    vector<int> ss;
    ss = split_size(s, ' ');
    for (int x : ss) {
      std::cout << x << std::endl;
    }
}