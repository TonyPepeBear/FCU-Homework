#include <iostream>
#include <stack>

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

point Point(int x, int y) {
    point p{};
    p.x = x;
    p.y = y;
    return p;
}

void printPoint(point p) { std::cout << "(" << p.x << ", " << p.y << ")" << std::endl; }

int main() {
    int n = 0;
    std::cin >> n;
    int *maze = (int *) malloc(n * n * sizeof(int));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> maze[i * n + j];
        }
    }

    std::stack<point> walk;
    walk.push(Point(0, 0));
    maze[0] = 2;
    while (!(walk.top().x == n - 1 && walk.top().y == n - 1)) {
        //        printPoint(walk.top());
        int x = walk.top().x;
        int y = walk.top().y;
        // up
        if (x - 1 >= 0 && maze[(x - 1) * n + y] == 1) {
            walk.push(Point(x - 1, y));
            maze[(x - 1) * n + y] = 2;
            continue;
        }
        // right
        if (y + 1 < n && maze[x * n + y + 1] == 1) {
            walk.push(Point(x, y + 1));
            maze[x * n + y + 1] = 2;
            continue;
        }
        // down
        if (x + 1 < n && maze[(x + 1) * n + y] == 1) {
            walk.push(Point(x + 1, y));
            maze[(x + 1) * n + y] = 2;
            continue;
        }
        // left
        if (y - 1 >= 0 && maze[x * n + y - 1] == 1) {
            walk.push(Point(x, y - 1));
            maze[x * n + y - 1] = 2;
            continue;
        }
        maze[x * n + y] = 0;
        walk.pop();
    }

    std::stack<char> x;
    while (!walk.empty()) {
        point p = walk.top();
        walk.pop();
        point pp;
        if (!walk.empty())
            pp = walk.top();
        else
            break;
        if (p.x != pp.x) {
            x.push(p.x > pp.x ? 'S' : 'N');
            continue;
        }
        if (p.y != pp.y) {
            x.push(p.y > pp.y ? 'E' : 'W');
            continue;
        }
    }

    while (!x.empty()) {
        std::cout << x.top();
        x.pop();
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
