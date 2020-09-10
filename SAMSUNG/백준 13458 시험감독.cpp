#include <iostream>

using namespace std;
typedef long long ll;

int arr[1000000];

int main() {
	int n, b, c;
	ll result = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cin >> b >> c;
	for (int i = 0; i < n; i++) {
		if ((arr[i] - b) <= 0)
			continue;
		if ((arr[i] - b) % c != 0) {
			result += ((arr[i] - b) / c) + 1;
		}
		else {
			result += ((arr[i] - b) / c);
		}
	}
	result += n;
	cout << result << "\n";
}