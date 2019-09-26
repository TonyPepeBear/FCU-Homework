#include <iostream> 
using namespace std;

int main() {
	for (int n = 100; n < 1000; n++) {
		int num[3];
		int t = n;
		for (int i = 0; i < 3; i++) {
			num[i] = t % 10;
			t /= 10;
		}
		//cout <<  num[0] << " " << num[1]  <<" " <<num[2] << endl;
		int total = (num[0] * num[0] * num[0]) + (num[1] * num[1] * num[1]) + num[2] * num[2] * num[2];
		if (n == total) {
			cout << n << endl;
		}
	}
} 
