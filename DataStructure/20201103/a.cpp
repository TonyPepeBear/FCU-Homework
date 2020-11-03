#include <iostream>

#define N 1000

typedef struct Node {
    char val;

    struct Node *next;
} node;

#define N 10000

node *reverse(node *head, node *tail) {
    node *n[N];
    int count = 0;
    node *t = head;
    while (t != NULL) {
        n[count] = t;
        count++;
        t = t->next;
    }
    n[0]->next = NULL;
    for (int i = count - 1; i > 0; --i) {
        n[i]->next = n[i - 1];
    }
    return n[count - 1];
}

int main() { return 0; }
