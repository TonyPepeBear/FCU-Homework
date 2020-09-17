#include <cstdio>

int main() {
    int count = 0;
    int c2 = 0;

    line1:
    if (count > 4) goto line2to4;
    printf("%s", "*");
    count++;
    goto line1;

    line2to4:
    count = 0;
    if (c2 > 2) {
        printf("\n");
        goto line5;
    }
    printf("\n");
    printf("%s", "*");
    count = 0;
    line2_2:
    if (count > 2) goto line2_3;
    printf("%s", " ");
    count++;
    goto line2_2;
    line2_3:
    printf("%s", "*");
    c2++;
    goto line2to4;

    line5:
    if (count > 4) goto end;
    printf("%s", "*");
    count++;
    goto line5;

    end:
    return 0;
}
