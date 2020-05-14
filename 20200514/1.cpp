#include <cstdio>
#include <cstdlib>

struct node {
    char value;
    node *next;
};

void push(node *head, char value) {
    node *newNode = (node *) malloc(sizeof(node));
    newNode->next = NULL;
    newNode->value = value;
    newNode->next = head->next;
    head->next = newNode;
}

char pop(node *head) {
    if (head->next != NULL) {
        char value = head->next->value;
        head->next = head->next->next;
        return value;
    } else {
        return '\0';
    }
}

void printAll(node *head) {
    char c = pop(head);
    while (c != '\0') {
        printf("%c", c);
        c = pop(head);
    }
    puts("");
}

int main() {
    node *head = (node *) malloc(sizeof(node));
    head->next = NULL;
    char s[100];
    scanf("%s", s);
    for (int i = 0; s[i] != '\0'; ++i) {
        push(head, s[i]);
    }
    printAll(head);
    return 0;
}

