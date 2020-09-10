#include <iostream>
#include <stack>

using namespace std;

stack<int> st;

int main() {
	int N;
	int result = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		if (num != 0) {
			st.push(num);
			result += num;
		}
		else {
			result -= st.top();
			st.pop();
		}
	}
	cout << result;
}