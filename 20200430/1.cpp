#include <cstdio>
#include <cstring>

#define FILE_NAME "hardware.txt"
#define N 100

struct tool {
    char name[20];
    int count;
    float cost;
};

void initData();

void insert();

void printAll();

void edit();

void del();

int main() {
    initData();
    insert();
    printAll();
    edit();
    del();

    return 0;
}

void initData() {
    FILE *f = fopen(FILE_NAME, "w+");
    for (int i = 0; i < 100; ++i) {
        fprintf(f, "%d none -1 -1.0\n", i + 1);
    }
    fclose(f);
}

void printAll() {
    FILE *f = fopen(FILE_NAME, "r");
    for (int i = 0; i < N; ++i) {
        tool t = {};
        int x;
        fscanf(f, "%d %s %d %f", &x, t.name, &t.count, &t.cost);
        printf("%d %s %d %f\n", x, t.name, t.count, t.cost);
    }
    fclose(f);
}

void insert() {
    FILE *f = fopen(FILE_NAME, "r");
    tool tools[N];
    for (int i = 0; i < N; ++i) {
        int t;
        fscanf(f, "%d %s %d %f", &t, tools[i].name, &tools[i].count, &tools[i].cost);
    }
    fclose(f);

    strcpy(tools[2].name, "電動沙光");
    tools[2].count = 7;
    tools[2].cost = 57.98;

    strcpy(tools[16].name, "鐵鎚");
    tools[16].count = 76;
    tools[16].cost = 11.99;

    strcpy(tools[23].name, "線鋸");
    tools[23].count = 21;
    tools[23].cost = 11.0;

    strcpy(tools[38].name, "除草機");
    tools[38].count = 3;
    tools[38].cost = 79.50;

    strcpy(tools[55].name, "電鋸");
    tools[55].count = 18;
    tools[55].cost = 99.99;

    strcpy(tools[67].name, "螺絲起子");
    tools[67].count = 106;
    tools[67].cost = 6.99;

    strcpy(tools[76].name, "大鎚");
    tools[76].count = 11;
    tools[76].cost = 21.50;

    strcpy(tools[82].name, "扳手");
    tools[82].count = 34;
    tools[82].cost = 7.50;

    f = fopen(FILE_NAME, "w+");
    for (int i = 0; i < N; ++i) {
        fprintf(f, "%d %s %d %f\n", i + 1, tools[i].name, tools[i].count, tools[i].cost);
    }
    fclose(f);
}

void edit() {
    FILE *f = fopen(FILE_NAME, "r");
    tool tools[N];
    for (int i = 0; i < N; ++i) {
        int t;
        fscanf(f, "%d %s %d %f", &t, tools[i].name, &tools[i].count, &tools[i].cost);
    }
    fclose(f);

    int x = 0;
    scanf("%d", &x);
    scanf("%s %d %f", tools[x - 1].name, &tools[x - 1].count, &tools[x - 1].cost);;

    f = fopen(FILE_NAME, "w+");
    for (int i = 0; i < N; ++i) {
        fprintf(f, "%d %s %d %f\n", i + 1, tools[i].name, tools[i].count, tools[i].cost);
    }
    fclose(f);
}

void del() {
    FILE *f = fopen(FILE_NAME, "r");
    tool tools[N];
    for (int i = 0; i < N; ++i) {
        int t;
        fscanf(f, "%d %s %d %f", &t, tools[i].name, &tools[i].count, &tools[i].cost);
    }
    fclose(f);

    int x = 0;
    scanf("%d", &x);
    strcpy(tools[x - 1].name, "none");
    tools[x - 1].count = -1;
    tools[x - 1].cost = -1;

    f = fopen(FILE_NAME, "w+");
    for (int i = 0; i < N; ++i) {
        fprintf(f, "%d %s %d %f\n", i + 1, tools[i].name, tools[i].count, tools[i].cost);
    }
    fclose(f);
}

/*
 83 扳手xxx 34222 7222.500000 3
 */