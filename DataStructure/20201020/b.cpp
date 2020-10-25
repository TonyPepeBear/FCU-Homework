#include <cstring>
#include <iostream>

int main() {
    // 62/3-42*+
    // 8293*/+8+
    double stack[100];
    int top = -1;

    char s[1000];
    std::cin >> s;
    for (int i = 0; i < strlen(s); ++i) {
        if (s[i] == '+') {
            stack[top - 1] = stack[top - 1] + stack[top];
            top--;
            continue;
        }
        if (s[i] == '-') {
            stack[top - 1] = stack[top - 1] - stack[top];
            top--;
            continue;
        }
        if (s[i] == '*') {
            stack[top - 1] = stack[top - 1] * stack[top];
            top--;
            continue;
        }
        if (s[i] == '/') {
            stack[top - 1] = stack[top - 1] / stack[top];
            top--;
            continue;
        }
        top++;
        stack[top] = (double) s[i] - '0';
    }
    printf("%lf\n", stack[top]);

    return 0;
}
