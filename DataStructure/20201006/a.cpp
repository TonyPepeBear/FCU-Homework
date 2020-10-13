#include <iostream>

void printMaze(int *maze, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << maze[i * n + j] << " ";
        }
        std::cout << std::endl;
    }
}

struct point {
    int x;
    int y;
};

struct stack {
    point *data;
    stack *next;
};

void push(stack *s, int x, int y) {
    while (s->next != NULL) {
        s = s->next;
    }
    stack *n = (stack *) malloc(sizeof(stack));

    n->data = (point *) malloc(sizeof(point));
    n->data->x = x;
    n->data->y = y;
    s->next = n;
}

void pop(stack *s) {
    while (s->next->next != NULL) {
        s = s->next;
    }
    s->next = NULL;
}

point *top(stack *s) {
    while (s->next != NULL) {
        s = s->next;
    }
    return s->data;
}

bool isEmpty(stack *s) {
    if (s->next == NULL) return true;
    return false;
}

int main() {
    int n = 0;
    std::cin >> n;
    int *maze = (int *) malloc(n * n * sizeof(int));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> maze[i * n + j];
        }
    }

    stack *walk = (stack *) malloc(sizeof(stack));
    push(walk, 0, 0);
    maze[0] = 2;
    while (!(top(walk)->x == n - 1 && top(walk)->y == n - 1)) {
        int x = top(walk)->x;
        int y = top(walk)->y;
        // up
        if (x - 1 >= 0 && maze[(x - 1) * n + y] == 1) {
            push(walk, x - 1, y);
            maze[(x - 1) * n + y] = 2;
            continue;
        }
        // right
        if (y + 1 < n && maze[x * n + y + 1] == 1) {
            push(walk, x, y + 1);
            maze[x * n + y + 1] = 2;
            continue;
        }
        // down
        if (x + 1 < n && maze[(x + 1) * n + y] == 1) {
            push(walk, x + 1, y);
            maze[(x + 1) * n + y] = 2;
            continue;
        }
        // left
        if (y - 1 >= 0 && maze[x * n + y - 1] == 1) {
            push(walk, x, y - 1);
            maze[x * n + y - 1] = 2;
            continue;
        }
        maze[x * n + y] = 0;
        pop(walk);
    }

    char s[1000];
    int len = 0;
    while (!isEmpty(walk)) {
        point *p = top(walk);
        pop(walk);
        point *pp;
        if (!isEmpty(walk))
            pp = top(walk);
        else
            break;
        if (p->x != pp->x) {
            len++;
            s[len] = p->x > pp->x ? 'S' : 'N';
            continue;
        }
        if (p->y != pp->y) {
            len++;
            s[len] = p->y > pp->y ? 'E' : 'W';
            continue;
        }
    }

    while (len > 0) {
        std::cout << s[len];
        len--;
    }
    std::cout << std::endl;

    return 0;
}

/*
3
1 1 0
0 1 1
1 0 1

7
1 1 1 1 1 1 1
0 0 0 0 1 0 1
1 1 1 0 1 0 1
1 0 1 0 1 0 0
1 0 1 1 1 0 0
1 0 0 0 0 0 0
1 1 1 1 1 1 1
 */
