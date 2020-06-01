#include <iostream>

using namespace std;

int newblackjack(int card[], int size, int m) {
	int sum = 0;
	int i = 0, j = 0, k = 0;
	int max = 0;
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			if (j == i) continue;
			for (k = 0; k < size; k++) {
				if (k == i || k == j) continue;
				sum = card[i] + card[j] + card[k];
				//cout << card[i] << " " << card[j] << " " << card[k]<<endl;
				if (max < sum && sum <= m  ) {
					max = sum;
					if (max == m) return max;
				}
			}
		}
	}
	return max;
}

int main() {
	int n = 0;
	int m = 0;
	int i = 0, j = 0;
	int cardNum;
	cin >> n;
	cin >> m;
	int *card = new int[n];
	for (i = 0; i < n; i++) {
		cin >> cardNum;
		card[i] = cardNum;
	}
	cout << newblackjack(card, n, m);
	
}