#include <iostream>
#include <string>
#include <vector>
using namespace std;


int main(int argc, char *argv[]) {
    vector<int> key;
    cout << "raw: " << argv[1] << endl;
    // 暗号化
    for(int i = 0; i < sizeof(argv[1]); i++) {
        if (islower(argv[1][i])) {
            key.push_back(i);
            argv[1][i] = 219 - argv[1][i]; 
        }
        
    }
    cout << "暗号化: " << argv[1] << endl;
    // 復号化
    for (int i : key) {
        argv[1][i] = 219 - argv[1][i]; 
    }
    cout << "復号化: " << argv[1] << endl;
}