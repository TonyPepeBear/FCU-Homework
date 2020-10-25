#include <cstring>
#include <iostream>

int valueIn(char c) {
    if (c == '+' || c == '-') { return 12; }
    if (c == '*' || c == '/') { return 13; }
    if (c == '^') { return 14; }
    return -1;
}

int valueOut(char c) {
    if (c == '+' || c == '-') { return 12; }
    if (c == '*' || c == '/') { return 13; }
    if (c == '^') { return 15; }
    return -1;
}

int main() {
    char stack[10000];
    int top = -1;
    char s[10000];
    std::cin >> s;
    for (int i = 0; i < strlen(s); ++i) {
        switch (s[i]) {
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                while (top > -1 && valueIn(stack[top]) >= valueOut(s[i])) {
                    std::cout << stack[top];
                    stack[top] = s[i];
                    top--;
                }
                top++;
                stack[top] = s[i];
                break;
            case '(':
                top++;
                stack[top] = s[i];
                break;
            case ')':
                while (top > -1 && stack[top] != '(') {
                    std::cout << stack[top];
                    top--;
                }
                if (top > -1) top--;
                break;
            default:
                std::cout << s[i];
        }
    }
    while (top > -1) {
        std::cout << stack[top];
        top--;
    }
    std::cout << std::endl;

    return 0;
}
