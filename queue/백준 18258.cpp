#include <iostream>
#include <stdio.h>
#include <queue>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

queue<int> q;

void _push() {
	int num;
	scanf("%d", &num);
	q.push(num);
}

void _pop() {
	if (q.empty() == 1) {
		cout << -1 << "\n";
	}
	else {
		cout << q.front() << "\n";
		q.pop();
	}
		
}

void _size() {
	cout << q.size() << "\n";
}

void _empty() {
	cout << q.empty() << "\n";
}

void _front() {
	if (q.empty()) {
		cout << -1 << "\n";
	}
	else
		cout << q.front() << "\n";
}

void _back() {
	if (q.empty()) {
		cout << -1 << "\n";
	}
	else
		cout << q.back() << "\n";
}

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		char inst[6];
		scanf("%s", &inst);
		if (strcmp(inst, "push") == 0) {
			_push();
		}
		else if (strcmp(inst, "pop") == 0) {
			_pop();
		}
		else if (strcmp(inst, "size") == 0) {
			_size();
		}
		else if (strcmp(inst, "empty") == 0) {
			_empty();
		}
		else if (strcmp(inst, "front") == 0) {
			_front();
		}
		else if (strcmp(inst, "back") == 0) {
			_back();
		}
	}
}
