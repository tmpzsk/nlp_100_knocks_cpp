#include <algorithm>
#include <iostream>
#include <regex>
#include <set>
#include <unordered_set>
#include <string>
#include <vector>
using namespace std;

// 和集合
unordered_set<string> unique(const vector<string> X, const vector<string> Y) {
    unordered_set<string> unique(X.begin(), X.end());
    unique.insert(Y.begin(), Y.end());
    return unique;
}

// 積集合
unordered_set<string> intersection(const vector<string> X, const vector<string> Y) {
    unordered_set<string> intersection;
    set_intersection(X.begin(), X.end(),
                     Y.begin(), Y.end(),
                     inserter(intersection, intersection.end()));
    return intersection;
}

// 差集合
unordered_set<string> difference(const vector<string> X, const vector<string> Y) {
    unordered_set<string> x_uniq(X.begin(), X.end());
    unordered_set<string> y_uniq(Y.begin(), Y.end());
    // count: 存在すれば削除
    for (string x: x_uniq) {
        if ( y_uniq.count(x) ) {
            y_uniq.erase(x);
        }
    }
    return y_uniq;
}

vector<string> n_gram(const string &s, const int n) {
    vector<string> elems;
    for (int i = 0; i <= s.size() - n; i++) {
        string k = s.substr(i, n);
        elems.push_back(k);
    }
    return elems;
}

int main() {
    const string x = "paraparaparadise";
    const string y = "paragraph";
    const string item = "se";
    vector<string> X;
    vector<string> Y;
    vector<string> result;
    // string
    X = n_gram(x, 2);
    Y = n_gram(y, 2);
    // seがあるかどうか
    if ( find(X.begin(), X.end(), item) != X.end()) {
       cout << "seあります" << endl;
    } else {
       cout << "seないです" << endl;
    }
    if ( find(Y.begin(), Y.end(), item) != Y.end()) {
       cout << "seあります" << endl;
    } else {
       cout << "seないです" << endl;
    }
    // 各集合の計算
    unordered_set<string> u = unique(X, Y);
    unordered_set<string> i = intersection(X, Y);
    unordered_set<string> d = difference(X, Y);
    for (string r : i) {
        cout << r << endl;
    }
}