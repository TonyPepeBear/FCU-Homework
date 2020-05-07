#include <cstdio>

struct node {
    char c;
    node *before;
    node *next;
};

void insert(node *n, char c) {
    node *newNode = new node();
    newNode->c = c;
    newNode->next = NULL;

    node *current = n;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    newNode->before = current;
}

void printN(node *n) {
    while (n != NULL) {
        printf("%c", n->c);
        n = n->next;
    }
    puts("");
}

node *getReverseNode(node *n) {
    while (n->next != NULL) {
        n = n->next;
    }
    node *m = new node();
    m->next = NULL;
    m->before = NULL;
    m->c = n->c;
    while (n->before != NULL) {
        insert(m, n->before->c);
        n = n->before;
    }
    return m;
}

int main() {
    node *n = new node();
    n->c = 'a';
    n->next = NULL;
    n->before = NULL;

    insert(n, 'b');
    insert(n, 'c');

    printN(n);
    node *m = getReverseNode(n);
    printN(m);

}
