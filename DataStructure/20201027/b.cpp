#include <cstring>
#include <iostream>

#define N 100

struct queue {
    char x;
    queue *next;
};

bool isEmpty(queue *self) { return self->next == NULL; }

void printQueue(queue *self) {
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

void add(queue *self, char x) {
    while (self->next != NULL) {
        self = self->next;
    }
    queue *q = (queue *) malloc(sizeof(queue));
    q->next = NULL;
    q->x = x;
    self->next = q;
}

char remove(queue *self) {
    char c = self->next->x;
    self->next = self->next->next;
    return c;
}

int queueCount(queue *self) {
    int c = 0;
    while (self->next != NULL) {
        c++;
        self = self->next;
    }
    return c;
}

int main() {
    char s[N];
    queue *d = (queue *) malloc(sizeof(queue));
    d->next = NULL;
    while (std::cin >> s) {
        if (!strcmp(s, "enque")) {
            char t[100];
            std::cin >> t;
            for (int i = 0; i < strlen(t); ++i) {
                if (queueCount(d) >= 10) {
                    std::cout << "Queue is full\n";
                    break;
                }
                add(d, t[i]);
            }
            continue;
        }
        if (!strcmp(s, "deque")) {
            int t;
            std::cin >> t;
            for (int i = 0; i < t; ++i) {
                if (isEmpty(d)) {
                    std::cout << "Queue is Empty\n";
                    break;
                }
                std::cout << remove(d) << std::endl;
            }
            continue;
        }
        if (!strcmp(s, "print")) {
            printQueue(d);
            continue;
        }
    }

    return 0;
}
