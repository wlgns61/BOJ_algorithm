#include <iostream>
#include <string>

using namespace std;

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string vps;
		int discriminator = 0;
		cin >> vps;
		for (int j = 0; j < vps.size(); j++) {
			if (vps[j] == '(') discriminator++;
			if (vps[j] == ')') discriminator--;
			if (discriminator < 0) {
				cout << "NO\n";
				break;
			}
		}
		if (discriminator == 0) cout << "YES\n";
		else if((discriminator > 0))cout << "NO\n";
	}
}