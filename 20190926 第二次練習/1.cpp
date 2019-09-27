#include <iostream>
using namespace std;

int main() {
    int time = 0;
    while (true) {
        cout << "Enter # hours worked (-1 to end):";
        cin >> time;
        if (time == -1) break;
        float rate = 0;
        cout << "Enter hourly rate of the worker ($00.00):";
        cin >> rate;
        float total = 0;
        if (time > 40) {
            int temp = time - 40;
            time = 40;
            total += temp * rate * 1.5;
        }
        total += time * rate;
        cout << "Salary is $" << total << endl;
    }
    return 0;
}
