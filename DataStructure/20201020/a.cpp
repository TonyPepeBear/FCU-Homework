#include <cstring>
#include <iostream>

#define N 10000

int main() {
    char queue[N];
    int first = 0;
    int tail = 0;
    char s[100];
    while (std::cin >> s) {
        if (!strcmp(s, "enque")) {
            std::cin >> s;
            for (int i = 0; i < strlen(s); ++i) {
                if (tail - first >= 10) {
                    std::cout << "Queue is full\n";
                    break;
                }
                queue[tail] = s[i];
                tail++;
            }
        } else if (!strcmp(s, "deque")) {
            int n;
            std::cin >> n;
            for (int i = 0; i < n; ++i) {
                if (tail - first <= 0) {
                    std::cout << "Queue is Empty\n";
                    break;
                }
                std::cout << queue[first] << std::endl;
                first++;
            }
        } else if (!strcmp(s, "print")) {
            if (first - tail == 0) break;
            for (int i = first; i < tail; ++i) {
                std::cout << queue[i];
                if (i != tail - 1) std::cout << " ";
            }
            std::cout << std::endl;
        }
    }

    return 0;
}
