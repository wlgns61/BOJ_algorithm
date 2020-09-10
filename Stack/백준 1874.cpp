#include <iostream>
#include <stack>
#include <vector>

using namespace std;

stack<int> st;
vector<char> printer;

int main() {
	int N;
	cin >> N;
	int pointer = 1;
	int num;
	cin >> num;
	for (int i = pointer; i <= num; i++) {
		st.push(i);
		pointer++;
		printer.push_back('+');
	}
	st.pop();
	printer.push_back('-');
	while (true) {
		if (pointer >= N + 1 && st.empty()) {
			break;
		}
		cin >> num;
		if (num >= pointer) {
			for (int i = pointer; i <= num; i++) {
				st.push(i);
				pointer++;
				printer.push_back('+');
			}
			st.pop();
			printer.push_back('-');
		}
		else if (num == st.top()) {
			st.pop();
			printer.push_back('-');
		}
		else {
			printer.push_back('x');
			break;
		}
	}
	if (printer[printer.size() - 1] == 'x') {
		cout << "NO\n";
	}
	else {
		for (int i = 0; i < printer.size(); i++) {
			cout << printer[i] << "\n";
		}
	}
	
}