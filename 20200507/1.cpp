#include <cstdio>
#include <cstdlib>

struct node {
    char c;
    node *nextPtr;
};

void link(node *a, node *b) {
    node *current = a;
    while (a->nextPtr != NULL) {
        a = a->nextPtr;
    }
    a->nextPtr = b;
}

void insert(node *n, char c) {
    node *newNode = new node();
    node *current = n;
    while (current->nextPtr != NULL) {
        current = current->nextPtr;
    }
    current->nextPtr = newNode;
    current = current->nextPtr;
    current->nextPtr = NULL;
    current->c = c;
}

void printNode(node *n) {
    node *current = n;
    while (current != NULL) {
        printf("%c", current->c);
        current = current->nextPtr;
    }
    puts("");
}

int main() {
    node n1 = {'1', NULL};
    insert(&n1, '2');
    insert(&n1, '3');
    node n2 = {'a', NULL};
    insert(&n2, 'b');
    insert(&n2, 'c');
    link(&n1, &n2);
    printNode(&n1);
    return 0;
}
