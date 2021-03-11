#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

int main(int argc, char *argv[]) {
    ifstream ifs(argv[1]);
    int n = atoi(argv[2]);
    string s;

    if (ifs.fail()) {
        cerr << "Failed to open file. " << argv[1] <<endl;
        return -1;
    }
    if ( n < 0 ) {
        cerr << "Please use positive number." << endl;
    }

    int cnt = 0;
    while(getline(ifs, s)) { 
        if ( cnt == n ) break;
        cout << s << endl;
        cnt++;
    }
}