#include <cstdio>

struct node {
    int value;
    node *next;
};

void insert(node *n, int value) {
    node *newNode = new node();
    newNode->value = value;
    newNode->next = NULL;
    node *current = n, *pre = NULL;
    while (current != NULL && value > current->value) {
        pre = current;
        current = current->next;
    }
    if (pre != NULL) {
        pre->next = newNode;
        newNode->next = current;
    }
}

void printNode(node *n) {
    node *current = n;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    puts("");
}

void merge(node *n, node *m) {
    while (m != NULL) {
        insert(n, m->value);
        m = m->next;
    }
}

int main() {
    node *n = new node();
    n->value = 1;
    n->next = NULL;

    insert(n, 2);
    insert(n, 10);


    node *m = new node();
    m->value = 2;
    m->next = NULL;
    insert(m, 5);
    insert(m, 3);
    printNode(n);
    printNode(m);
    merge(n, m);

    printNode(n);
    return 0;
}
