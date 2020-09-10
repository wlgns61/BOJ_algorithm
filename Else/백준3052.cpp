#include <iostream>

using namespace std;

int main() {
	int hashtable[42] = {0};
	int num=0, i=0;
	int count = 0;
	for (i = 0; i < 10; i++) {
		cin >> num;
		hashtable[num % 42] = 1;
	}
	for (i = 0; i < 42; i++) {
		if (hashtable[i] == 1) count++;
	}
	cout << count << endl;
}