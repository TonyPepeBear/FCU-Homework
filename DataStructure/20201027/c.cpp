#include <cstring>
#include <iostream>

#define N 10000

struct person {
    char *name;
    int arrTime;
    int needTime;
    int startTime;
};

struct pQueue {
    person *pers;
    pQueue *next;
};

int queueCount(pQueue *self) {
    int c = 0;
    while (self->next != NULL) {
        c++;
        self = self->next;
    }
    return c;
}

void pQueuePush(pQueue *self, person *p, int startTime) {
    while (self->next != NULL) {
        self = self->next;
    }
    self->next = (pQueue *) malloc(sizeof(pQueue));
    self->next->pers = p;
    self->next->pers->startTime = startTime;
    self->next->next = NULL;
}

struct table {
    pQueue *queue;
};

void printPersons(person **p, int count) {
    return;
    for (int i = 0; i < count; ++i) {
        std::cout << p[i]->name << std::endl;
    }
}

int main() {
    // init tables
    int tableCount = 0;
    std::cin >> tableCount;
    table *tables[N];
    for (int i = 0; i < tableCount; ++i) {
        tables[i] = (table *) malloc(sizeof(table));
        tables[i]->queue = (pQueue *) malloc(sizeof(pQueue));
        tables[i]->queue->next = NULL;
        tables[i]->queue->pers = NULL;
    }
    // init persons
    person *persons[N];
    int personCount = 0;
    char s[N];
    int arr, need;
    while (std::cin >> s >> arr >> need) {
        if (!strcmp(s, "999")) break;
        persons[personCount] = (person *) malloc(sizeof(person));
        persons[personCount]->name = (char *) malloc(sizeof(char) * N);
        strcpy(persons[personCount]->name, s);
        persons[personCount]->arrTime = arr;
        persons[personCount]->needTime = need;
        persons[personCount]->startTime = -1;
        personCount++;
    }

    printPersons(persons, personCount);

    int clock = 0;
    int finishCount = 0, dealCount = 0;
    while (finishCount < personCount) {
        // finish work
        for (int i = 0; i < tableCount; ++i) {
            if (queueCount(tables[i]->queue) &&
                tables[i]->queue->next->pers->startTime + tables[i]->queue->next->pers->needTime ==
                    clock) {
                std::cout << tables[i]->queue->next->pers->name << " " << clock << " " << i
                          << std::endl;
                finishCount++;
                tables[i]->queue->next = tables[i]->queue->next->next;
                if (tables[i]->queue->next != NULL) {
                    tables[i]->queue->next->pers->startTime = clock;
                }
            }
        }
        // give work
        int minTable = 0;
        for (int i = 0; i < tableCount; ++i) {
            minTable =
                queueCount(tables[i]->queue) < queueCount(tables[minTable]->queue) ? i : minTable;
        }
        for (int i = 0; i < personCount; ++i) {
            if (persons[i]->arrTime == clock) {
                pQueuePush(tables[minTable]->queue, persons[i], clock);
            }
        }
        clock++;
    }
    return 0;
}
