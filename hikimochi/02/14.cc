#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    const int n = atoi(argv[2]);
    if (auto ifs = std::ifstream(argv[1])) {
        if (n > 0) {
            std::string s;
            int cnt = 0;
            // 指定された行番号まで標準出力
            while(std::getline(ifs, s)) { 
                if ( cnt == n ) break;
                std::cout << s << std::endl;
                cnt++;
            }
        } else std::cerr << "Please use positive number." << std::endl;
    } else std::cerr << "Failed to open file. " << argv[1] << std::endl;
}