#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> v;
int __start;
int _end;
bool _reverse;

void make_array(int arr_num, string str_arr) {
	v.clear();
	string num = "";
	for (unsigned int i = 0; i < str_arr.size(); i++) {
		if (int('0') <= int(str_arr[i]) && int(str_arr[i]) <= int('9')) {
			num += str_arr[i];
		}
		else {
			if (num.compare("") != 0) {
				v.push_back(atoi(num.c_str()));
			}
			num = "";
		}
	}
	_reverse = false;
	__start = 0;
	_end = v.size() - 1;
}

bool v_empty() {
	if (__start > _end) {
		return true;
	}
	else {
		return false;
	}
}

void v_reverse() {
	if (v_empty() == true) return;
	else {
		if (_reverse == true) _reverse = false;
		else _reverse = true;
	}
}

void v_delete() {
	if (_reverse == false) {
		__start++;
	}
	else {
		_end--;
	}
}

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		
		string command = "";
		string str_arr = "";
		int arr_num = 0;

		cin >> command >> arr_num >> str_arr;

		make_array(arr_num, str_arr);

		for (unsigned int j = 0; j < command.size(); j++) {
			if (command[j] == 'R') {
				v_reverse();
			}
			else if (command[j] == 'D') {
				v_delete();
			}
		}
		
		if (v_empty() == false) {
			if (_reverse == false) {
				cout << "[";
				for (int j = __start; j <= _end - 1; j++) {
					cout << v[j] << ",";
				}
				cout << v[_end];
				cout << "]\n";
			}
			else {
				cout << "[";
				for (int j = _end; j > __start; j--) {
					cout << v[j] << ",";
				}
				cout << v[__start];
				cout << "]\n";
			}
		}
		else if (__start - _end == 1) {
			cout << "[]\n";
		}
		else if (v_empty() == true) {
			cout << "error\n";
		}
	}
}