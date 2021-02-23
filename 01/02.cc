#include <iostream>
#include <string>
using namespace std;

int main() {
    string p = "パトカー";
    string t = "タクシー";
    string output = "";
    for (int i = 0; i <= 12; i = i + 3) {
        output = output + p.substr(i, 3) + t.substr(i, 3);
    }
    cout << output << endl;
}