#include <cstring>
#include <iostream>

#define N 100

struct stack {
    int x;
    stack *next;
};

bool isEmpty(stack *self) { return self->next == NULL; }

void printStack(stack *self) {
    if (isEmpty(self)) return;
    self = self->next;
    bool _ = false;
    do {
        if (_) {
            printf(" ");
        } else {
            _ = true;
        }
        std::cout << self->x;
        self = self->next;
    } while (self != NULL);
    std::cout << std::endl;
}

int stackCount(stack *self) {
    int c = 0;
    while (self->next != NULL) {
        c++;
        self = self->next;
    }
    return c;
}

void push(stack *self, int x) {
    while (self->next != NULL) {
        self = self->next;
    }
    stack *n = (stack *) malloc(sizeof(stack));
    n->next = NULL;
    n->x = x;
    self->next = n;
}

int pop(stack *self) {
    while (self->next->next != NULL) {
        self = self->next;
    }
    int x = self->next->x;
    self->next = NULL;
    return x;
}

int main() {
    char s[N];
    stack *d = (stack *) malloc(sizeof(stack));
    d->next = NULL;
    while (std::cin >> s) {
        if (!strcmp(s, "push")) {
            int x = 0;
            std::cin >> x;
            if (stackCount(d) >= 10) {
                std::cout << "The stack is Full\n";
                continue;
            }
            push(d, x);
            continue;
        }
        if (!strcmp(s, "pop")) {
            if (isEmpty(d)) {
                std::cout << "The stack is Empty\n";
                continue;
            }
            std::cout << pop(d) << std::endl;
            continue;
        }
        if (!strcmp(s, "print")) {
            printStack(d);
            continue;
        }
    }

    return 0;
}
