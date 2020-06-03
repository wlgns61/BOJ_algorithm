#include <iostream>

using namespace std;

int main() {
	int A = 0, B = 0, V = 0;
	int day = 1;
	int left = 0;
	cin >> A >> B >> V;
	day = (V - B) / (A - B);
	if ((V - B) % (A - B) != 0)
		day++;
	cout << day;
}