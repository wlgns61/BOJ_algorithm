#include <iostream>
#include <math.h>

using namespace std;

int main() {
	int A = 1, B = 1, C = 1, i = 1;
	int num_length = 0;
	int numtable[10] = {0};
	cin >> A >> B >> C;
	int multi = A * B * C;
	while (multi>i) {
		i *= 10;
		num_length++;
	}
	for (i = num_length-1; i > -1; i--) {
		int position_value = (multi / pow(10, i));
		multi = (multi % int(pow(10, int(i))));
		numtable[position_value]++;
	}
	for (i = 0; i < 10; i++) {
		cout << numtable[i]<<endl;
	}

}