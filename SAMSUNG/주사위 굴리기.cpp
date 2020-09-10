#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int map[20][20];
int n, m;
int x, y;
int num;

typedef struct dice_info {
	int one;
	int two;
	int three;
	int four;
	int five;
	int six;
};

dice_info dice;

void move1(dice_info tmp){ //µ¿
	dice = { tmp.three, tmp.two, tmp.six, tmp.one, tmp.five ,tmp.four};
	y++;
}
void move2(dice_info tmp){ //¼­
	dice = { tmp.four, tmp.two, tmp.one, tmp.six, tmp.five, tmp.three };
	y--;
}
void move3(dice_info tmp){ //ºÏ
	dice = { tmp.two, tmp.six, tmp.three, tmp.four, tmp.one, tmp.five };
	x--;
}
void move4(dice_info tmp){ //³²
	dice = { tmp.five, tmp.one, tmp.three, tmp.four, tmp.six, tmp.two };
	x++;
}

void solve(int num) {

	while (--num >= 0) {
		int inst;
		cin >> inst;

		if (inst == 1) {   //µ¿
			if (y + 1 >= m)
				continue;
			move1(dice);
		}
		else if (inst == 2) {  //¼­
			if (y - 1 < 0)
				continue;
			move2(dice);
		}
		else if (inst == 3) {  //ºÏ
			if (x - 1 < 0)
				continue;
			move3(dice);
		}
		else {
			if (x + 1 >= n)  //³²
				continue;
			move4(dice);
		}
		if (map[x][y] == 0)
			map[x][y] = dice.one;
		else {
			dice.one = map[x][y];
			map[x][y] = 0;
		}
		cout << dice.six << "\n";
	}
}

int main() {

	cin >> n >> m >> x >> y >> num;
	dice = { 0,0,0,0,0,0 };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	solve(num);
}