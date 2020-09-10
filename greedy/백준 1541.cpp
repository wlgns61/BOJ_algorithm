#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> num_arr;

int main() {
	string expression;
	cin >> expression;
	string num = "";
	int result = 0;
	int plus = 1, minus = 0;
	bool flag = false;
	if (expression[0] == '-') {
		plus = 0;
	}
	for (int i = 0; i < expression.size(); i++) {
		if (int('0') <= int(expression[i]) && int('9') >= int(expression[i])) {
			num += expression[i];
		}
		else if (expression[i] == '+') {
			if (flag == false) {
				num_arr.push_back(atoi(num.c_str()));
				plus++;
				num = "";
			}
			else {
				num_arr.push_back(atoi(num.c_str()));
				minus++;
				num = "";
			}
		}
		else if (expression[i] == '-') {
			flag = true;
			num_arr.push_back(atoi(num.c_str()));
			minus++;
			num = "";
		}
	}
	num_arr.push_back(atoi(num.c_str()));
	for (int i = 0; i < num_arr.size(); i++) {
		if (plus > 0) {
			result += num_arr[i];
			plus--;
		}
		else {
			result -= num_arr[i];
		}
	}
	cout << result;

}