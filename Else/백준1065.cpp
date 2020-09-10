#include <iostream>

using namespace std;

int hansu(int n) {
	int count = 0;
	int i = 0;
	if (n == 1000)
		n = 999;
	if (n < 100) count = n;
	else if(100 <= n < 1000){
		count = 99;
		for (i = 100; i <= n; i++) {
			if ((i % 10) + (i / 100) == 2 * ((i % 100) / 10)) {
				count++;
			}
		}
	}
	return count;
}

int main() {
	int n = 0;
	int count = 0;
	cin >> n;
	count = hansu(n);	
	cout << count;
}