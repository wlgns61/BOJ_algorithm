#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	while (true) {

		string str;
		stack<char> st;

		getline(cin, str);

		if (str.compare(".") == 0) break;

		int i = 0;
		for (i = 0; i < str.size(); i++) {
			if (str[i] == '.') {
				if (st.empty()) {
					cout << "yes\n";
					str.clear();
					break;
				}
				else {
					cout << "no\n";
					str.clear();
					break;
				}
			}
			if (str[i]=='[' || str[i] == '(') {
				st.push(str[i]);
			}
			else if (str[i] == ']') {
				if (st.empty()) {
					cout << "no\n";
					break;
				}
				if (st.top() == '[') {
					st.pop();
				}
				else {
					cout << "no\n";
					break;
				}
			}
			else if (str[i] == ')') {
				if (st.empty()) {
					cout << "no\n";
					break;
				}
				if (st.top() == '(') {
					st.pop();
				}
				else {
					cout << "no\n";
					break;
				}
			}
		}
		if (i == str.size()) cout << "yes\n";
	}
}