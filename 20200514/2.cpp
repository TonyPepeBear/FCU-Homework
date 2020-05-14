#include <cstdio>
#include <cstdlib>

struct node {
    int value;
    node *next;
};

void insert(node *head, int value) {
    node *newNode = (node *) malloc(sizeof(node));
    newNode->value = value;
    newNode->next = NULL;
    while (head->next != NULL)
        head = head->next;
    head->next = newNode;
}

node *searchList(node *head, int value) {
    if (head == NULL) return NULL;
    if (head->value == value) return head;
    return searchList(head->next, value);
}

int main() {
    node *head = (node *) malloc(sizeof(node));
    insert(head, 1);
    insert(head, 2);
    insert(head, 4);
    insert(head, 5);
    int f = 0;
    scanf("%d", &f);
    node *search = searchList(head, f);
    printf("%d\n", search == NULL ? -1 : search->value);
    return 0;
}



