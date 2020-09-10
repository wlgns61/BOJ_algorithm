#include <iostream>

using namespace std;

int main() {
	int min, max;
	int temp;
	int num = 0;
	cin >> num;
	cin >> temp;
	min = temp;
	max = temp;
	for (int i = 1; i < num; i++) {
		cin >> temp;
		if(temp < min) min = temp;
		if(max < temp) max = temp;
	}
	cout << min << " " << max << endl;
}