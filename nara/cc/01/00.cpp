#include <iostream>
using namespace std;

string reverse_s(string s) {
    int n = s.length();
    string r_s = "";
    for (int i = 0; i < n; ++i) {
        r_s = s[i] + r_s;
    }
    return r_s;
}

int main() {
    string s = "stressed";
    string rev_s = reverse_s(s);
    cout << rev_s << endl;
}