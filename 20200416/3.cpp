#include <cstdio>

int main() {
    FILE *file = fopen("datasize.txt", "wb+");
    fprintf(file, "char\t\t\t%lu\n", sizeof(char));
    fprintf(file, "unsigned char\t%lu\n", sizeof(unsigned char));
    fprintf(file, "short int\t\t\t%lu\n", sizeof(short int));
    fprintf(file, "unsigned short int\t\t\t%lu\n", sizeof(unsigned short int));
    fprintf(file, "int\t\t\t%lu\n", sizeof(int));
    fprintf(file, "long int\t\t\t%lu\n", sizeof(long int));
    fprintf(file, "unsigned long int\t\t\t%lu\n", sizeof(unsigned long int));
    fprintf(file, "float\t\t\t%lu\n", sizeof(float));
    fprintf(file, "double\t\t\t%lu\n", sizeof(double));
    fprintf(file, "long double\t\t\t%lu\n", sizeof(long double));
    return 0;
}
