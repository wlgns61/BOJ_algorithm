#include <iostream>

using namespace std;

int main() {
	int arr[8];
	int i = 0;
	int checker=0;
	cin >> arr[0];
	for (i = 1; i < 8; i++) {
		cin >> arr[i];
		if (arr[i - 1] < arr[i]) checker++;
		if (arr[i - 1] > arr[i]) checker--;
	}
	if (checker == 7) cout << "ascending";
	else if (checker == -7) cout << "descending";
	else cout << "mixed";
}