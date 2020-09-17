#include <cstdio>
#include <cstdlib>

struct node {
    char value;
    node *next;
};

void insert(node *head, char value) {
    while (head->next != NULL)
        head = head->next;
    node *newNode = (node *) malloc(sizeof(node));
    newNode->value = value;
    newNode->next = NULL;
    head->next = newNode;
}

char getValue(node *head) {
    char c = '\0';
    if (head->next != NULL) {
        c = head->next->value;
        head->next = head->next->next;
    }
    return c;
}

void print(node *head) {
    char c = getValue(head);
    while (c != '\0') {
        printf("%c", c);
        c = getValue(head);
    }
}

int main() {
    node *head = (node *) malloc(sizeof(node));
    head->next = NULL;
    insert(head, 'a');
    insert(head, 'e');
    insert(head, 'i');
    insert(head, 'o');
    insert(head, 'u');
    print(head);
    return 0;
}
