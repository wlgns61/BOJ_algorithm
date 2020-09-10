#include <iostream>

using namespace std;
int t, k;

typedef struct info {
	char front, back, right, left, up, down;
};

info cube[3][3][3];
info tmp[3][3][3];

void copy() {
	for (int h = 0; h < 3; h++)  //높이
		for (int x = 0; x < 3; x++)  //x
			for (int y = 0; y < 3; y++)  //y
				tmp[h][x][y] = cube[h][x][y];
}

void init() {
	for (int h = 0; h < 3; h++)  //높이
		for (int x = 0; x < 3; x++)  //x
			for (int y = 0; y < 3; y++)  //y
				cube[h][x][y] = { 'r','o','b','g','w','y' };
}

void rotate_front_back(int x, char absdir) { //절대적 위치
	if (absdir == '+') 
		for (int h = 0; h < 3; h++) 
			for (int y = 0; y < 3; y++) {
				info temp = tmp[h][x][y];
				tmp[h][x][y] = { temp.front, temp.back, temp.up, temp.down, temp.left, temp.right };
				cube[y][x][2 - h] = tmp[h][x][y];
			}
	else 
		for (int h = 0; h < 3; h++) 
			for (int y = 0; y < 3; y++) {
				info temp = tmp[h][x][y];
				tmp[h][x][y] = { temp.front, temp.back, temp.down, temp.up, temp.right, temp.left };
				cube[2- y][x][h] = tmp[h][x][y];
			}
}

void rotate_right_left(int y, char absdir) { //절대적 위치
	if (absdir == '+')
		for (int h = 0; h < 3; h++)
			for (int x = 0; x < 3; x++) {
				info temp = tmp[h][x][y];
				tmp[h][x][y] = { temp.down, temp.up, temp.right, temp.left, temp.front, temp.back };
				cube[x][2 - h][y] = tmp[h][x][y];
			}
	else 
		for (int h = 0; h < 3; h++)
			for (int x = 0; x < 3; x++) {
				info temp = tmp[h][x][y];
				tmp[h][x][y] = { temp.up, temp.down, temp.right, temp.left, temp.back, temp.front};
				cube[2 - x][h][y] = tmp[h][x][y];
			}
}

void rotate_up_down(int h, char absdir) { //절대적 위치
	if (absdir == '+')
		for (int x = 0; x < 3; x++)
			for (int y = 0; y < 3; y++) {
				info temp = tmp[h][x][y];
				tmp[h][x][y] = { temp.right, temp.left, temp.back, temp.front, temp.up, temp.down };
				cube[h][2 - y][x] = tmp[h][x][y];
			}
	else 
		for (int x = 0; x < 3; x++)
			for (int y = 0; y < 3; y++) {
				info temp = tmp[h][x][y];
				tmp[h][x][y] = { temp.left, temp.right, temp.front, temp.back, temp.up, temp.down };
				cube[h][y][2 - x] = tmp[h][x][y];
			}
}

void solve(char side, char dir) {
	char absdir;
	if (side == 'F' && dir == '+')
		rotate_front_back(0, '+');
	else if (side == 'F' && dir == '-')
		rotate_front_back(0, '-');
	else if (side == 'B' && dir == '+')
		rotate_front_back(2, '-');
	else if (side == 'B' && dir == '-')
		rotate_front_back(2, '+');
	else if (side == 'U' && dir == '+')
		rotate_up_down(0, '+');
	else if (side == 'U' && dir == '-')
		rotate_up_down(0, '-');
	else if (side == 'D' && dir == '+')
		rotate_up_down(2, '-');
	else if (side == 'D' && dir == '-')
		rotate_up_down(2, '+');
	else if (side == 'L' && dir == '+')
		rotate_right_left(0, '-');
	else if (side == 'L' && dir == '-')
		rotate_right_left(0, '+');
	else if (side == 'R' && dir == '+')
		rotate_right_left(2, '+');
	else if (side == 'R' && dir == '-')
		rotate_right_left(2, '-');
}

void print() {
	for (int x = 2; x >= 0; x--) {
		for (int y = 0; y < 3; y++) 
			cout << cube[0][x][y].up;
		cout << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while (--t >= 0) {
		cin >> k;
		init();
		while (--k >= 0) {
			char side, dir;
			cin >> side >> dir;
			copy();
			solve(side, dir);
		}
		print();
	}
}
