#include <cstdio>
#include <cstring>

#define N 10

struct person {
    char lastName[15];
    char firstName[15];
    char age[4];
};

void initData() {
    FILE *file = fopen("nameage.txt", "wb+");
    for (int i = 0; i < N; ++i) {
        struct person p = {"unassigned", "unassigned", "0"};
        fprintf(file, "%s %s %s\n", p.lastName, p.firstName, p.age);
    }
    fclose(file);
}

void insertData() {
    FILE *file = fopen("nameage.txt", "r");
    person p[N] = {};
    for (int i = 0; i < N; ++i) {
        fscanf(file, "%s%s%s", p[i].lastName, p[i].firstName, p[i].age);
    }
    fclose(file);
    person pInsert = {};
    scanf("%s%s%s", pInsert.lastName, pInsert.firstName, pInsert.age);
    for (int i = 0; i < N; ++i) {
        if (strcmp(p[i].lastName, "unassigned") == 0) {
            strcpy(p[i].lastName, pInsert.lastName);
            strcpy(p[i].firstName, pInsert.firstName);
            strcpy(p[i].age, pInsert.age);
            break;
        }
    }
    file = fopen("nameage.txt", "wb+");
    for (int i = 0; i < N; ++i) {
        fprintf(file, "%s %s %s\n", p[i].lastName, p[i].firstName, p[i].age);
    }
    fclose(file);
}

void editData() {
    FILE *file = fopen("nameage.txt", "r");
    person p[N] = {};
    for (int i = 0; i < N; ++i) {
        fscanf(file, "%s%s%s", p[i].lastName, p[i].firstName, p[i].age);
    }
    fclose(file);
    person pInsert = {};
    bool findFlag = false;
    scanf("%s%s%s", pInsert.lastName, pInsert.firstName, pInsert.age);
    for (int i = 0; i < N; ++i) {
        if (strcmp(p[i].lastName, pInsert.lastName) == 0 && strcmp(p[i].firstName, pInsert.firstName) == 0) {
            strcpy(p[i].age, pInsert.age);
            findFlag = true;
            break;
        }
    }
    if (findFlag) {
        file = fopen("nameage.txt", "wb+");
        for (int i = 0; i < N; ++i) {
            fprintf(file, "%s %s %s\n", p[i].lastName, p[i].firstName, p[i].age);
        }
        fclose(file);
    } else {
        puts("No Info");
    }
}

void deleteData() {
    FILE *file = fopen("nameage.txt", "r");
    person p[N] = {};
    for (int i = 0; i < N; ++i) {
        fscanf(file, "%s%s%s", p[i].lastName, p[i].firstName, p[i].age);
    }
    fclose(file);
    person pDelete = {};
    scanf("%s%s", pDelete.lastName, pDelete.firstName);
    for (int i = 0; i < N; ++i) {
        if (strcmp(p[i].lastName, pDelete.lastName) == 0 && strcmp(p[i].firstName, pDelete.firstName) == 0) {
            strcpy(p[i].lastName, "unassigned");
            strcpy(p[i].firstName, "unassigned");
            strcpy(p[i].age, "0");
            break;
        }
    }
    file = fopen("nameage.txt", "wb+");
    for (int i = 0; i < N; ++i) {
        fprintf(file, "%s %s %s\n", p[i].lastName, p[i].firstName, p[i].age);
    }
    fclose(file);
}

int main() {
    initData();
    insertData();
    insertData();
    insertData();
    editData();
    deleteData();
    return 0;
}

