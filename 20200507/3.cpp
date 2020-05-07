#include <cstdio>
#include <ctime>
#include <random>

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
    } else {
        newNode->next = n;
        n = newNode;
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

int sum(node *n) {
    int s = 0;
    while (n != NULL) {
        s += n->value;
        n = n->next;
    }
    return s;
}

int getSize(node *n) {
    int count = 0;
    while (n != NULL) {
        count++;
        n = n->next;
    }
    return count;
}

float ave(node *n) {
    return ((float) sum(n) / (float) getSize(n));
}

int main() {
    node *n = new node();
    srandom(time(NULL));
    n->value = 0;
    n->next = NULL;
    for (int i = 0; i < 25; ++i) {
        insert(n, (int) random() % 100);
    }
    n = n->next;

    printNode(n);
    printf("%f\n", ave(n));
    return 0;
}

