#include <iostream>
#include <string>
using namespace std;

template<typename S, typename T, typename U>
void echo(S a, T b, U c) {
    cout << a << "時の" << b << "は" << c << endl;
}

int main(int argc, char *argv[]) {
    echo(argv[1], argv[2], argv[3]);
}