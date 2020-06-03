#include <iostream>

using namespace std;

int main() {
	int tri[3] = {0};
	int max = 0; int i = 0;
	int max_index = 0;
	while (true) {
		max = 0;
		for (i = 0; i < 3; i++) {
			cin >> tri[i];
			if (max <= tri[i]) {
				max = tri[i];
				max_index = i;
			}
		}
		if (tri[0] == 0 && tri[1] == 0 && tri[2] == 0) break;
		if (tri[max_index % 3] * tri[max_index % 3] ==
			tri[(max_index + 1) % 3] * tri[(max_index + 1) % 3]
			+ tri[(max_index + 2) % 3] * tri[(max_index + 2) % 3]) {
			cout << "right\n";
		}
		else cout << "wrong\n";
	}
	
}