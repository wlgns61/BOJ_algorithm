#include <iostream>
#include <stack>
#include <string>

using namespace std;

stack<int> v;

void st_push(int num) {
	v.push(num);
}

void st_pop() {
	if (v.size() == 0) {
		cout << -1 << "\n";
	}
	else {
		v.pop();
	}
}

void st_size() {
	cout << v.size() << "\n";
}

void st_empty() {
	if (v.empty()) {
		cout << 1 << "\n";
	}
	else {
		cout << 0 << "\n";
	}
}

void st_top() {
	if (v.size() == 0) {
		cout << -1 << "\n";
	}
	else {
		cout << v.top() << "\n";
	}
}

int main() {
	int N; 
	cin >> N;
	for (int i = 0; i < N; i++) {
		string instruct;
		cin >> instruct;
		if (instruct.find("push") == 0) {
			int num;
			cin >> num;
			st_push(num);
		}
		else if (instruct.compare("pop") == 0) st_pop();
		else if (instruct.compare("size") == 0) st_size();
		else if (instruct.compare("empty") == 0) st_empty();
		else if (instruct.compare("top") == 0) st_top();
	}
}