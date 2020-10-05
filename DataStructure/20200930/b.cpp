#include <iostream>
#include <string>

#define N 101
#define M 101

int max(int a, int b) { return a > b ? a : b; }

int main() {
    std::string strings[N];
    int n = 0;
    int lenMax = 0;
    std::cin >> n;
    if (n > 0) getline(std::cin, strings[0]);
    for (int i = 0; i < n; ++i) {
        getline(std::cin, strings[i]);
        lenMax = max(lenMax, strings[i].length());
    }
    for (int i = 0; i < lenMax; ++i) {
        for (int j = n - 1; j > -1; --j) {
            if (i < strings[j].length()) {
                std::cout << strings[j].at(i);
            } else {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }

    return 0;
}
