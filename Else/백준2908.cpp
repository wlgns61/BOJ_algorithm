#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	string num1;
	string num2;
	int str2int1;
	int str2int2;
	int i = 0;
	
	cin >> num1 >> num2;
	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());
	str2int1 = atoi(num1.c_str());
	str2int2 = atoi(num2.c_str());
	if (str2int1 < str2int2)
		cout << str2int2;
	else
		cout << str2int1;
}