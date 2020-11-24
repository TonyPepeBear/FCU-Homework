#include <cstring>
#include <iostream>

#define N 100

typedef struct Node {
    char val;
    struct Node *next;
} node;

int count(node **list) {
    if (*list == NULL) return 0;
    int count = 0;
    node *n = *list;
    while (n != NULL) {
        count++;
        n = n->next;
    }
    return count;
}

void insertNode(node **list, char val, int position) {
    if (*list == NULL) {
        *list = (node *) malloc(sizeof(node));
        (*list)->val = val;
        (*list)->next = NULL;
        return;
    }
    if (position == 0) {
        node *n = (node *) malloc(sizeof(node));
        n->next = *list;
        n->val = val;
        *list = n;
        return;
    }
    node *t = *list;
    for (int i = 0; i < position - 1 && t != NULL; ++i) {
        t = t->next;
    }
    if (t == NULL) {
        puts("Index out of range");
        return;
    }
    node *n = (node *) malloc(sizeof(node));
    n->val = val;
    n->next = t->next;
    t->next = n;
}

void del(node **list, int position) {
    if (*list == NULL) {
        puts("List is Empty");
        return;
    }
    if (position >= count(list)) {
        puts("Index out of range");
        return;
    }
    if (position == 0) {
        std::cout << (*list)->val << std::endl;
        *list = (*list)->next;
        return;
    }
    node *t = *list;
    for (int i = 0; i < position - 1; ++i) {
        t = t->next;
    }
    std::cout << t->next->val << std::endl;
    t->next = t->next->next;
}

void print(node **list) {
    if (*list == NULL) return;
    node *t = *list;
    bool first = true;
    while (t != NULL) {
        if (!first) { putchar(' '); }
        first = false;
        putchar(t->val);
        t = t->next;
    }
    puts("");
}

int main() {
    node *list = NULL;
    char s[N];
    while (std::cin >> s) {
        if (!strcmp(s, "insert")) {
            char val[5];
            int position = 0;
            std::cin >> val >> position;
            insertNode(&list, val[0], position);
        } else if (!strcmp(s, "print")) {
            print(&list);
        } else if (!strcmp(s, "delete")) {
            int position = 0;
            std::cin >> position;
            del(&list, position);
        }
    }
    return 0;
}
