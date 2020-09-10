#include <iostream>

using namespace std;

int factorial(int num) {
	
	if (num == 1 || num == 0) return 1;
	return num * factorial(num - 1);
}

int main() {
	int num = 0;
	int result;
	cin >> num;
	result = factorial(num);
	cout << result;
}
 