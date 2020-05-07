#include <iostream>

#define nullptr NULL

using namespace std;

struct node {
    int value;
    node *next;
};

/*
 * insert *value* to end the of list
 */
void insert(node *list, int value) {
    node *newNode = new node();
    newNode->value = value;
    newNode->next = nullptr;
    while (list->next != nullptr) {
        list = list->next;
    }
    list->next = newNode;
}

void sort(node *head) {
    node *i = head;
    while (i != nullptr) {
        node *j = i->next;
        while (j != nullptr) {
            if (i->value > j->value) {
                int temp = i->value;
                i->value = j->value;
                j->value = temp;
            }
            j = j->next;
        }
        i = i->next;
    }
}


void print(node *a) {
    while (a != nullptr) {
        cout << a->value << " ";
        a = a->next;
    }
    cout << endl;
}

/*
 * link *b* to the end of *a*
 */
void link(node *a, node *b) {
    while (a->next != nullptr) {
        a = a->next;
    }
    a->next = b;
}


int main() {
    node *a = new node();
    a->value = 1;
    a->next = nullptr;
    node *b = new node();
    b->value = 4;
    b->next = nullptr;

    insert(a, 3);
    insert(a, 10);
    insert(a, 8);

    insert(b, 2);
    insert(b, 5);

    print(a);
    print(b);

    link(a, b);
    print(a);
    sort(a);

    print(a);

}
