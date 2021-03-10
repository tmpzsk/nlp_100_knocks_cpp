#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;


int main(int argc, char *argv[]) {
    vector<int> key;
    ifstream ifs(argv[1]);
    string s;

    if (ifs.fail()) {
        cerr << "Failed to open file." << endl;
        return -1;
    }

    int cnt = 0;
    while (getline(ifs, s)) {
        cnt++;
    }
    cout << cnt << endl;
}