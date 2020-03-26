#include <cstdio>

int main() {
    char s[][15] = {
            "Taipei",
            "Hualien",
            "Pingdong",
            "Jiayi",
            "Kaohsiung"
    };
    char *c[5];
    for (int i = 0; i < 5; ++i) {
        c[i] = s[i];
    }
    for (int i = 0; i < 5; ++i) {
        for (int j = i; j < 5; ++j) {
            if (c[i][0] > c[j][0]) {
                char *temp = c[i];
                c[i] = c[j];
                c[j] = temp;
            }
        }
    }
    for (int i = 0; i < 5; ++i) {
        printf("%s\n", c[i]);
    }
}
