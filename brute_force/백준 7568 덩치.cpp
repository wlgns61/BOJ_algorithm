#include <iostream>

using namespace std;

typedef struct person {
	int w;
	int h;
	int rank = 0;
} person;

void find_rank(person guys[], int n) {
	int i = 0, j = 0;
	for (i = 0; i < n-1; i++) {
		for (j = i+1; j < n; j++) {
			if (guys[i].w > guys[j].w && guys[i].h > guys[j].h) {
				guys[j].rank++;
			}
			else if (guys[i].w < guys[j].w && guys[i].h < guys[j].h) {
				guys[i].rank++;
			}
		}
	}
	for (i = 0; i < n; i++) {
		cout << guys[i].rank << " ";
	}
}

int main() {
	int n = 0, i = 0;
	int w, h;
	cin >> n;
	person *guys = new person[n];
	for (i = 0; i < n; i++) {
		cin >> w >> h;
		guys[i].w = w;
		guys[i].h = h;
		guys[i].rank = 1;
	}
	find_rank(guys, n);
}