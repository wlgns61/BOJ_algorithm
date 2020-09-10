#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int num;
	cin >> num;
	int two = 0, five = 0;
	int tmp;
	for (int i = 1; i <= num; i++) {
		tmp = i;
		while (true) {
			if (tmp % 2 == 0) {
				tmp /= 2;
				two++;
			}
			else if (tmp % 5 == 0) {
				tmp /= 5;
				five++;
			}
			else {
				break;
			}
		}
	}	
	cout << min(two, five);
}