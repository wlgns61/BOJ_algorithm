#include <iostream>
#include <string>
using namespace std;
int n, m, x;
char s[11];

int main() {
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%s", &s);
		if (s[0] == 'a' && s[1] == 'd') {
			scanf("%d", &x);
			n = n | (1 << x);
		}
		else if (s[0] == 'r') {
			scanf("%d", &x);
			n = n & ~(1 << x);
		}
		else if (s[0] == 'c') {
			scanf("%d", &x);
			if ((n & (1 << x)) == (1 << x)) cout << 1<<"\n";
			else cout << 0 <<"\n";
		}
		else if (s[0] == 't') {
			scanf("%d", &x);
			if ((n & (1 << x)) == (1 << x)) {
				n = n & ~(1 << x);
			}
			else {
				n = n | (1 << x);
			}
		}
		else if (s[0] == 'a') {
			n = (1 >> 21) - 1;
		}
		else {
			n = 0;
		}
	}
}