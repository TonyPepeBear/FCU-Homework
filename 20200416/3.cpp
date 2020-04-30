#include <iostream>

using namespace std;

int main() {
    int a, b;

//    scanf("%d", &a);
    cin >> a;

//    printf("%d\n", a);
    cout << a << endl;

//    scanf("%d%d", &a, &b);
    cin >> a >> b;

//    printf("%d %d\n", a,b);
    cout << a << " " << b << endl;


    int nums[100];

    for (int i = 0; i < 100; ++i) {
        cin >> nums[i];
    }

    for (int j = 0; j < 100; ++j) {
        cout << nums[j] << endl;
    }


}
