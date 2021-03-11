#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
    ifstream ifs1("./13/col1.txt");
    ifstream ifs2("./13/col2.txt");
    ofstream outputfile(argv[1]);
    string s1, s2;

    while ( ( getline(ifs1, s1) && getline(ifs2, s2) ) || ( getline(ifs2, s2) || getline(ifs2, s2) ) ) {
        outputfile << s1 << "\t" << s2 << endl;
    }
    outputfile.close();
}