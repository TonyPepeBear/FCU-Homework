#include <cmath>
#include <iostream>

#define N 100

void printNum(const double* num, int n, int m);

int main() {
    int n = 0;
    std::cin >> n;
    double* num = (double*) malloc(n * N * sizeof(double));
    double xx = 0;

    int m = 0;
    std::cin >> xx;
    while (xx != -999) {
        num[m * (n + 1)] = xx;
        for (int i = 0; i < n; ++i) {
            std::cin >> num[m * (n + 1) + i + 1];
        }
        m++;
        std::cin >> xx;
    }

    if (n > m) {
        std::cout << "Infinite solutions" << std::endl;
        return 0;
    }

    n++;

    printNum(num, n, m);

    for (int i = 0; i < m; ++i) {
        for (int t = i + 1; t < m; ++t) {
            double r = -1 * num[t * n + i] / num[i * n + i];

            for (int j = 0; j < n; ++j) {
                num[t * n + j] = num[t * n + j] + r * num[i * n + j];
            }
        }
    }

    printNum(num, n, m);

    for (int i = 0; i < m; ++i) {
        int counter = 0;
        for (int j = 0; j < n - 1; ++j) {
            if (fabs(num[i * n + j]) < 0.0001) { counter++; }
        }
        if (counter == n - 1) {
            std::cout << "No solution" << std::endl;
            return 0;
        }
    }

    for (int i = 0; i < m * n + n; ++i) {
        if (std::isnan(num[i]) || std::isinf(num[i])) {
            std::cout << "Infinite solutions" << std::endl;
            return 0;
        }
    }

    for (int i = 0; i < m; ++i) {
        int counter = 0;
        for (int j = 0; j < n; ++j) {
            if (fabs(num[i * n + j]) < 0.0001) { counter++; }
        }
        if (counter >= n) {
            std::cout << "Infinite solutions" << std::endl;
            return 0;
        }
    }

    std::cout << "The only solution" << std::endl;
    return 0;
}

void printNum(const double* num, int n, int m) {
    return;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << num[i * n + j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}