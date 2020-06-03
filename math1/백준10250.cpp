#include <iostream>

using namespace std;

void find_room(int H, int W, int N) {
	int floor = 1;
	int number = 1;
	floor = N % H;
	if (floor == 0) floor = H;
	number = (N-1) / H + 1;
	cout << floor;
	if (number < 10) cout << '0' << number;
	else cout << number;
	cout << endl;
}

int main() {
	int H = 1, W = 1, N = 1;
	int i = 0;
	int test = 0;
	cin >> test;
	for (i = 0; i < test; i++) {
		cin >> H >> W >> N;
		find_room(H, W, N);
	}
}