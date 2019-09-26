#include <iostream>
using namespace std;

int biggest(int nums[]) {
	int max = -1;
	for (int i = 0; i < 10; i++) {
		if (nums[i] > max) {
			max = nums[i];
		}
	}
	return max;
}

int main() {
	int nums[10] = {0};
	int input = 0, counter = 0;
	while (counter < 10) {
		cout << "Input number " << counter + 1 << ": ";
		cin >> input; 
		if (input < 0) {
			cout << "input wrong" << endl;
			continue;
		}
		nums[counter] = input;
		cout << "Counter:" << counter + 1 << "\tNumber:" << input << "\tBiggest:" << biggest(nums) << endl; 
		counter ++;
	}
	return 0;
}
