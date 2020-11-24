#include <cstdio>
typedef struct Node {
    int val;
    struct Node *next;
} node;

node *getPtr(node **list, int x) {
    node *n = *list;
    for (int i = 0; i < x && n != NULL; ++i) {
        n = n->next;
    }
    return n;
}

void swapNodes(node **list, int x, int y) {
    if (x == y) return;
    if (x == 0) {
        if (y == 1) {
            node *t = (*list)->next->next;
            node *u = (*list);
            *list = (*list)->next;
            (*list)->next = u;
            u->next = t;
            return;
        }
        node *yNode = *list, *yPre = *list;
        for (int i = 0; i < y; ++i) {
            yPre = yNode;
            yNode = yNode->next;
        }
        node *t = yNode->next;
        yNode->next = (*list)->next;
        (*list)->next = t;

        yPre->next = *list;
        (*list) = yNode;

        return;
    }
    if (y - x == 1) {
        node *xNode = *list, *xPre = *list, *yNode = *list, *yPre = *list;
        for (int i = 0; i < x; ++i) {
            xPre = xNode;
            xNode = xNode->next;
        }
        node *next = xNode->next->next;
        xPre->next = xNode->next;
        xNode->next->next = xNode;
        xNode->next = next;

        return;
    }
    node *xNode = *list, *xPre = *list, *yNode = *list, *yPre = *list;
    for (int i = 0; i < x; ++i) {
        xPre = xNode;
        xNode = xNode->next;
    }
    for (int i = 0; i < y; ++i) {
        yPre = yNode;
        yNode = yNode->next;
    }
    node *t = yNode->next;
    yNode->next = xNode->next;
    xNode->next = t;

    xPre->next = yNode;
    yPre->next = xNode;
}

void sort(node **list) {
    node *n = *list;
    int nn = 0;
    while (n != NULL) {
        node *m = n->next;
        int mm = nn + 1;
        while (m != NULL) {
            if (n->val > m->val) {
                swapNodes(list, nn, mm);
                n = getPtr(list, nn);
                m = getPtr(list, mm);
            }
            m = m->next;
            mm++;
        }
        n = n->next;
        nn++;
    }
}
