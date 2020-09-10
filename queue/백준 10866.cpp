#include <iostream>
#include <stdio.h>
#include <queue>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

deque<int> q;

void _push_front() {
	int num;
	scanf("%d", &num);
	q.push_front(num);
}

void _push_back() {
	int num;
	scanf("%d", &num);
	q.push_back(num);
}

void _pop_front() {
	if (q.empty() == 1) {
		cout << -1 << "\n";
	}
	else {
		cout << q.front() << "\n";
		q.pop_front();
	}
}

void _pop_back() {
	if (q.empty() == 1) {
		cout << -1 << "\n";
	}
	else {
		cout << q.back() << "\n";
		q.pop_back();
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
		if (strcmp(inst, "push_front") == 0) {
			_push_front();
		}
		else if (strcmp(inst, "push_back") == 0) {
			_push_back();
		}
		else if (strcmp(inst, "pop_front") == 0) {
			_pop_front();
		}
		else if (strcmp(inst, "pop_back") == 0) {
			_pop_back();
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