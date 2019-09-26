#include <iostream>
using namespace std;

bool isPrime(int n) {
	for (int i = 2; i < n / 2 + 1; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

int main() {
	int num = 0;
	while (cin >> num) {
		if (isPrime(num)) {
			cout << num << " is a prime number." << endl;
		} else {
			cout << num << " is not a prime number." << endl;
		}
	}
	return 0;
}
