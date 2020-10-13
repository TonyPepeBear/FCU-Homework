#include <cstring>
#include <iostream>

#define N 11

int main() {
    int num[N];
    int len = 0;
    char s[10];
    while (std::cin >> s) {
        if (!strcmp(s, "push")) {
            if (len >= 10) {
                std::cout << "The stack is Full" << std::endl;
            } else {
                len++;
                std::cin >> num[len];
            }
        }
        if (!strcmp(s, "pop")) {
            if (len <= 0) {
                std::cout << "The stack is Empty" << std::endl;
            } else {
                std::cout << num[len] << std::endl;
                len--;
            }
        }
        if (!strcmp(s, "print")) {
            for (int i = 1; i < len + 1; ++i) {
                std::cout << num[i];
                if (i < len) { std::cout << " "; }
            }
            std::cout << std::endl;
        }
    }
    return 0;
}

/*
push
10
push
30
print
pop
pop
pop
 */
