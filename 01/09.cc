#include <iostream>
#include <random>
#include <string>
#include <vector>
using namespace std;


int main(int argc, char *argv[]) {
    mt19937 get_rand_mt;

    // 4文字以下
    if (sizeof(argv[1]) <= 4 ) {
        cout << "raw: " << argv[1] << endl;
        return 0;
    }

    string s = argv[1];
    shuffle( s.begin() + 1, s.end() - 1, get_rand_mt);

    cout << "shuffle: " << s << endl;
} 