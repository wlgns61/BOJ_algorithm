#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;
	int i;
	int size;
	cin >> size;
	cin >> str;
	int num = 0, sum = 0;
	for (i = 0; i < size; i++) {
		num = int(str[i])-int('0');
		sum += num;
	}
	cout << sum;
}