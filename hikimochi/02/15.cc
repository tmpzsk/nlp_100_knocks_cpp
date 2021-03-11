#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
    ifstream ifs(argv[1]);
    int n = atoi(argv[2]);
    string s;
    vector<string> vec;


    if (ifs.fail()) {
        cerr << "Failed to open file. " << argv[1] <<endl;
        return -1;
    }
    if ( n < 0 ) {
        cerr << "Please use positive number." << endl;
    }

    // 行数のカウント
    while(getline(ifs, s)) { 
        vec.push_back(s);
    }
    // 出力を始める行番号（ファイルの行数を超えるときはすべて出力）
    int start_line;
    if ( (vec.size() - n) < 0 ) start_line = 0;
    else start_line = vec.size() - n;
    // 出力
    for (int i = 0; i < vec.size(); ++i) {
        if (i >= start_line) {
            cout << vec[i] << endl;
        }
    }
} 