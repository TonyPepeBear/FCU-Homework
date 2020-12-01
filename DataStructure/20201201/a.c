#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10000

struct treeNode {
    int value;
    struct treeNode *left;
    struct treeNode *right;
};

struct treeNode *newNode(int value) {
    struct treeNode *n = (struct treeNode *) malloc(sizeof(struct treeNode));
    n->value = value;
    n->left = NULL;
    n->right = NULL;
    return n;
}

struct linkNode {
    struct treeNode *data;
    struct linkNode *next;
};

void push(struct linkNode **node, struct treeNode *data) {
    if (*node == NULL) {
        *node = (struct linkNode *) malloc(sizeof(struct linkNode));
        struct linkNode *n = *node;
        n->next = NULL;
        n->data = data;
        return;
    }
    struct linkNode *n = *node;
    while (n->next != NULL) {
        n = n->next;
    }
    n->next = (struct linkNode *) malloc(sizeof(struct linkNode));
    n = n->next;
    n->data = data;
    n->next = NULL;
}

struct treeNode *pop(struct linkNode **node) {
    if (*node == NULL) return NULL;
    if ((*node)->next == NULL) {
        struct treeNode *d = (*node)->data;
        *node = NULL;
        return d;
    }
    struct linkNode *n = *node;
    while (n->next->next != NULL) {
        n = n->next;
    }
    struct treeNode *d = n->next->data;
    n->next = NULL;
    return d;
}

void insert(struct treeNode **head, int value) {
    if (*head == NULL) {
        *head = newNode(value);
        return;
    }
    struct treeNode *h = *head;
    if (value <= h->value) {
        insert(&(h->left), value);
    } else {
        insert(&(h->right), value);
    }
}

void inOrder(struct treeNode *head) {
    int isFirst = 1;
    struct linkNode *stack = NULL;
    struct treeNode *cur = head;
    while (cur != NULL) {
        push(&stack, cur);
        cur = cur->left;
    }
    while (cur != NULL || stack != NULL) {
        struct treeNode *p = pop(&stack);
        if (!isFirst) { printf(" "); }
        isFirst = 0;
        printf("%d", p->value);
        cur = p->right;
        while (cur != NULL) {
            push(&stack, cur);
            cur = cur->left;
        }
    }
}

void preOrder(struct treeNode *head) {
    int isFirst = 1;
    struct linkNode *stack = NULL;
    push(&stack, head);
    while (stack != NULL) {
        struct treeNode *p = pop(&stack);
        if (p == NULL) continue;
        if (!isFirst) { printf(" "); }
        isFirst = 0;
        printf("%d", p->value);
        push(&stack, p->right);
        push(&stack, p->left);
    }
}

void postOrder(struct treeNode *head) {
    struct linkNode *s1 = NULL, *s2 = NULL;
    push(&s1, head);
    while (s1 != NULL) {
        struct treeNode *p = pop(&s1);
        if (p == NULL) continue;
        push(&s2, p);
        push(&s1, p->left);
        push(&s1, p->right);
    }
    int isFirst = 1;
    while (s2 != NULL) {
        if (!isFirst) { printf(" "); }
        isFirst = 0;
        printf("%d", pop(&s2)->value);
    }
}

int main() {
    int n = 0;
    struct treeNode *tree = NULL;
    while (scanf("%d", &n) != 0) {
        insert(&tree, n);
    }

    char s[N];
    while (scanf(" %s", s) != EOF) {
        if (!strcmp(s, "InOrder")) {
            inOrder(tree);
            printf("\n");
        }
        if (!strcmp(s, "PreOrder")) {
            preOrder(tree);
            printf("\n");
        }
        if (!strcmp(s, "PostOrder")) {
            postOrder(tree);
            printf("\n");
        }
    }
    return 0;
}
