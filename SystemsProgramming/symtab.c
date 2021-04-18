#include <stdlib.h>

struct Symbol {
    char name[20];
    unsigned value;
};

struct Symtab {
    int size;
    struct Symbol symbols[1000];
};

struct Symtab *newSymtab() {
    struct Symtab *s = malloc(sizeof(struct Symtab));
    return s;
}

void insertSymbol(struct Symtab *tab, char name[20], unsigned value) {
    struct Symbol s;
    strcpy(s.name, name);
    s.value = value;
    tab->symbols[tab->size++] = s;
}
