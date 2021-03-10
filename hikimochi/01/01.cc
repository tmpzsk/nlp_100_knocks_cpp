#include <iostream>
#include <string>
using namespace std;

int main() {
    string str = "パタトクカシーー";
    string output = str.substr(0, 3) + str.substr(6, 3) + str.substr(12, 3) + str.substr(18, 3);
    cout << output << endl;
}