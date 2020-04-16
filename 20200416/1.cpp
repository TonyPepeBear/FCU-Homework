#include <cstdio>

int main() {
    FILE *file = fopen("bank.txt", "wb");
    fputs("帳戶編號\t名稱\t\t餘額\t\n"
          "100\tAlen Jones\t348.17\n"
          "300\tMary Smith\t27.19\n"
          "500\tSam Sharp\t0.00\n"
          "700\tSuzy Green\t-14.22\n",
          file
    );
    fputs("\n\n\n", file);

    fputs(
            "帳戶編號\t金額\n"
            "100\t27.14\n"
            "300\t62.11\n"
            "400\t100.56\n"
            "900\t82.17\n",
            file
    );
    fclose(file);
    return 0;
}

