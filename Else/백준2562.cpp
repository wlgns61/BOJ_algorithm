#include <iostream>

using namespace std;

int main() {
	int num;
	int max;
	int count = 1;
	cin >> num;
	max = num;
	for (int i = 1; i < 9; i++) {
		cin >> num;
		if (num > max) {
			max = num;
			count = i+1;
		} 
	}
	cout << max << "\n" << count << endl;
}