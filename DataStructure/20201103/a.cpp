#include <iostream>

#define N 1000

typedef struct Node {
    char val;

    struct Node *next;
} node;

#define N 10000

node *reverse(node *head, node *tail) {
    node *n = NULL, *p = NULL, *c = head;
    while (c != NULL) {
        n = p;
        p = c;
        c = c->next;
        p->next = n;
    }
    return p;
}

int main() { return 0; }
