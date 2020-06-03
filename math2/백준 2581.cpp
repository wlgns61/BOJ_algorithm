#include <iostream>

using namespace std;

int main() {
	int min = 10001;
	int sum = 0;
	int m = 0, n = 0;
	int i = 0, j = 0;
	int count = 0;
	cin >> m >> n;
	for (i = m; i <= n; i++) {
		count = 0;
		for (j = 1; j <= i; j++) {
			if (i%j == 0) count++;
		}
		if (count == 2) {
			sum += i;
			if (min > i)
				min = i;
		}
	}
	if (min == 10001) min = -1;
	if(sum>0) cout << sum << endl;
	cout << min;
}