#include <cstdio>
#include <cctype>

int main(int argc, char *argv[]) {

    FILE *op = fopen(argv[1], "r");
    FILE *wr = fopen(argv[2], "wb+");

    while (!feof(op)) {
        char temp;
        int x = fscanf(op, "%c", &temp);
        if (x > 0) fprintf(wr, "%c", toupper(temp));
    }

    fclose(op);
    fclose(wr);
    return 0;
}
