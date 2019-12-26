#include <cstdio>

#define STUDENT 3
#define EXAM 3

void printArray(int grade[STUDENT][EXAM]);

void printMin(int grade[STUDENT][EXAM]);

void printMax(int grade[STUDENT][EXAM]);

void printAverage(int grade[STUDENT][EXAM]);

int main() {
    int grade[STUDENT][EXAM] = {
            {30, 40, 50},
            {60, 70, 80},
            {0,  50, 100}
    };
    printf(
            "Enter a choice:\n"
            "   0   Print the array of grades\n"
            "   1   Find the Min of grades\n"
            "   2   Find the Max of grades\n"
            "   3   Print the average on all test of each student\n"
            "   4   End Program\n"
    );
    int choice = 0;
    void (*f[4])(int[STUDENT][EXAM]) = {printArray, printMin, printMax, printAverage};
    while (scanf("%d", &choice) != EOF) {
        if (!(choice >= 0 && choice <= 3))
            return 0;
        (*f[choice])(grade);
    }
}

void printArray(int grade[STUDENT][EXAM]) {
    for (int i = 0; i < STUDENT; ++i) {
        printf("Student %d:\n\t", i + 1);
        for (int j = 0; j < EXAM; ++j) {
            printf("%d, ", grade[i][j]);
        }
        printf("\n");
    }
}

void printMin(int grade[STUDENT][EXAM]) {
    int min = grade[0][0];
    for (int i = 0; i < STUDENT; ++i) {
        for (int j = 0; j < EXAM; ++j) {
            if (grade[i][j] < min) min = grade[i][j];
        }
    }
    printf("min: %d\n", min);
}

void printMax(int grade[STUDENT][EXAM]) {
    int max = grade[0][0];
    for (int i = 0; i < STUDENT; ++i) {
        for (int j = 0; j < EXAM; ++j) {
            if (grade[i][j] > max) max = grade[i][j];
        }
    }
    printf("max: %d\n", max);
}

void printAverage(int grade[STUDENT][EXAM]) {
    for (int i = 0; i < STUDENT; ++i) {
        int sum = 0;
        for (int j = 0; j < EXAM; ++j) {
            sum += grade[i][j];
        }
        int average = sum / EXAM;
        printf("Student %d average: %d\n", i + 1, average);
    }
}


