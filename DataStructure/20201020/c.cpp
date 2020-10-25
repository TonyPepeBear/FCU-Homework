#include <cstring>
#include <iostream>

int main() {
    char s[1000];
    char stack[1000];
    int top = -1;

    std::cin >> s;
    for (int i = 0; i < strlen(s); ++i) {
        switch (s[i]) {
            case '(':
                top++;
                stack[top] = '(';
                break;
            case '[':
                if (stack[top] == '(') {
                    std::cout << "Illegal\n";
                    return 0;
                }
                top++;
                stack[top] = '[';
                break;
            case '{':
                if (stack[top] == '(' || stack[top] == '[') {
                    std::cout << "Illegal\n";
                    return 0;
                }
                top++;
                stack[top] = '{';
                break;
            case ')':
                if (stack[top] != '(') {
                    std::cout << "Illegal\n";
                    return 0;
                }
                top--;
                break;
            case ']':
                if (stack[top] != '[') {
                    std::cout << "Illegal\n";
                    return 0;
                }
                top--;
                break;
            case '}':
                if (stack[top] != '{') {
                    std::cout << "Illegal\n";
                    return 0;
                }
                top--;
                break;
        }
    }
    std::cout << "Legal\n";

    return 0;
}
