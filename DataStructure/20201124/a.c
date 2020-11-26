#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

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
    if (head != NULL) {
        inOrder(head->left);
        printf("%d ", head->value);
        inOrder(head->right);
    }
}

void preOrder(struct treeNode *head) {
    if (head != NULL) {
        printf("%d ", head->value);
        preOrder(head->left);
        preOrder(head->right);
    }
}

void postOrder(struct treeNode *head) {
    if (head != NULL) {
        postOrder(head->left);
        postOrder(head->right);
        printf("%d ", head->value);
    }
}

struct linkNode {
    struct treeNode *data;
    struct linkNode *next;
};

void push(struct linkNode *head, struct treeNode *data) {
    if (head->next == NULL) {
        head->next = (struct linkNode *) malloc(sizeof(struct linkNode));
        head->next->next = NULL;
        head->next->data = data;
        return;
    }
    push(head->next, data);
}

void leaveOrder(struct treeNode *head) {
    struct linkNode *link = (struct linkNode *) malloc(sizeof(struct linkNode));
    link->data = head;
    link->next = NULL;
    struct linkNode *temp = link;

    while (temp != NULL) {
        if (temp->data->left != NULL) { push(link, temp->data->left); }
        if (temp->data->right != NULL) { push(link, temp->data->right); }
        temp = temp->next;
    }
    temp = link;
    bool f = true;
    while (temp != NULL) {
        if (!f) { printf(" "); }
        f = false;
        printf("%d", temp->data->value);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n = 0;
    struct treeNode *tree = NULL;
    while (scanf("%d", &n) != EOF) {
        insert(&tree, n);
    }
    inOrder(tree);
    printf("\n");

    preOrder(tree);
    printf("\n");

    postOrder(tree);
    printf("\n");

    leaveOrder(tree);

    return 0;
}
