#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>

int main(int argc, char *argv[]) {
    // filename
    std::ifstream ifs(argv[1]);
    // line number
    int n = atoi(argv[2]);
    if (ifs.fail()) {
        std::cerr << "Failed to open file. " << argv[1] << std::endl;
        return -1;
    }
    if ( n < 0 ) {
        std::cerr << "Please use positive number." << std::endl;
    }

    std::string s;
    std::vector<std::string> vec;
    // 行数のカウント
    while(getline(ifs, s)) { 
        vec.push_back(s);
    }
    // 出力を始める行番号（ファイルの行数を超えるときはすべて出力）
    const int start_line = vec.size() - n < 0 ? 0 : vec.size() - n;
    // 出力
    for (int i = 0; i < vec.size(); ++i) {
        if (i >= start_line) {
            std::cout << vec[i] << std::endl;
        }
    }
} 