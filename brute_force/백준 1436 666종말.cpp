#include <iostream>
#include <string>

using namespace std;

int main() {
	int n;
	int count = 0;
	cin >> n;
	int title = 665;
	string s;
	while (++title) {
		s = to_string(title);
		if (s.find("666") != -1) {
			count++;
		}
		if (count == n) break;
	}
	cout << s;
}