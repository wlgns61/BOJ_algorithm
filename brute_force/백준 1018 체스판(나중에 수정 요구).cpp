#include <iostream>
#define W false
#define B true

using namespace std;

int main() {
	int m,n;
	int min;
	char num = ' ';
	int i=0,j=0;
	int istart = 0, iend = 0;
	int jstart = 0, jend = 0;
	cin >> m >> n;
	bool **board = new bool*[m];
	for (i = 0; i < m; i++) {
		board[i] = new bool[n];
	}
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			cin >> num;
			if (num == 'W') board[i][j] = W;
			else if (num == 'B') board[i][j] = B;
		}
	}
	while (true) {
		int count = 0;
		int count1 = 0;
		int count2 = 0;
		iend = istart + 7;
		jend = jstart + 7;
		if (board[istart][jstart] == W) {
			for (i = istart; i <= iend; i++) {
				for (j = jstart; j <= jend; j++) {
					if (((i - istart) % 2 == 0 && (j - jstart) % 2 == 0) || ((i - istart) % 2 == 1 && (j - jstart) % 2 == 1)) {
						if (board[i][j] == B) count1++;
					}
					if (((i - istart) % 2 == 0 && (j - jstart) % 2 == 1) || ((i - istart) % 2 == 1 && (j - jstart) % 2 == 0)) {
						if (board[i][j] == W) count1++;
					}
				}
			}
			for (i = istart; i <= iend; i++) {
				for (j = jstart; j <= jend; j++) {
					if (((i - istart) % 2 == 0 && (j - jstart) % 2 == 0) || ((i - istart) % 2 == 1 && (j - jstart) % 2 == 1)) {
						if (board[i][j] == W) count2++;
					}
					if (((i - istart) % 2 == 0 && (j - jstart) % 2 == 1) || ((i - istart) % 2 == 1 && (j - jstart) % 2 == 0)) {
						if (board[i][j] == B) count2++;
					}
				}
			}
		}
		else {
			for (i = istart; i <= iend; i++) {
				for (j = jstart; j <= jend; j++) {
					if (((i - istart) % 2 == 0 && (j - jstart) % 2 == 0) || ((i - istart) % 2 == 1 && (j - jstart) % 2 == 1)) {
						if (board[i][j] == B) count1++;
					}
					if (((i - istart) % 2 == 0 && (j - jstart) % 2 == 1) || ((i - istart) % 2 == 1 && (j - jstart) % 2 == 0)) {
						if (board[i][j] == W) count1++;
					}
				}
			}
			for (i = istart; i <= iend; i++) {
				for (j = jstart; j <= jend; j++) {
					if (((i - istart) % 2 == 0 && (j - jstart) % 2 == 0) || ((i - istart) % 2 == 1 && (j - jstart) % 2 == 1)) {
						if (board[i][j] == W) count2++;
					}
					if (((i - istart) % 2 == 0 && (j - jstart) % 2 == 1) || ((i - istart) % 2 == 1 && (j - jstart) % 2 == 0)) {
						if (board[i][j] == B) count2++;
					}
				}
			}
		}
		if(count1 > count2)  count=count2;
		else count = count1;
		if (istart == 0 && jstart==0) min = count;
		if (count < min) min = count;
		istart++;
		if (iend + 1 == m) {
			istart = 0;
			jstart++;
		}
		if (iend + 1 == m && jend + 1 == n) break;
	}
	cout << min;
}