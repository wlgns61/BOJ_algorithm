#include <iostream>

using namespace std;

int main() {
	int x = 0, y = 0, test = 0;
	int i = 0;
	unsigned int distance; //여기 부분 중요
	cin >> test;
	for (i = 0; i < test; i++) {
		int count = 1, range = 1, range_bound = 0, j = 0;
		cin >> x >> y;
		distance = y - x;
		while (true) {
			if (range <= distance && distance <= range + range_bound) {
				break;
			}
			count++;
			j++;
			range = (range + range_bound) + 1;
			if (j % 2 == 0) range_bound++;
		}
		cout << count << endl;
	}
}