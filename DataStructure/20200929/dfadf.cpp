#include <iostream>
using namespace std;
int main() {
    int num[101] = {-1}, c = 0;
    for (int i = 0; i < 101; ++i) {
        num[i] = -1;
    }
    for (int i = 0; i < 100; i++) {
        cin >> num[i];
        if (cin.bad()) { break; }
        c++;
    }
    int counter = 0;
    for (int i = 0; i < c; i++) {
        if (num[i] == 0) { counter++; }
    }
    for (int i = 0; i < c; i++) {
        if (num[i] > 0) { cout << num[i] << " "; }
    }
    for (int i = 0; i < counter - 1; i++) {
        cout << "0 ";
    }
}