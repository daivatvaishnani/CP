#include <bits/stdc++.h>

using namespace std;

char grid[10][10];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	// freopen("in","r",stdin);
	// freopen("out", "w", stdout);
	int x, y;
	for(int i = 1; i < 10; ++i) {
		for(int j = 1; j < 10; ++j) {
			cin >> grid[i][j];
		}
	}
	cin >> x >> y;
	x %= 3, y %= 3;
	if(x == 0 && y == 0) {
		x = 7;
		y = 7;
	}
	if(x == 0 && y == 1) {
		x = 7;
		y = 1;
	}
	if(x == 0 && y == 2) {
		x = 7;
		y = 4;
	}
	if(x == 1 && y == 0) {
		x = 1;
		y = 7;
	}
	if(x == 1 && y == 1) {
		x = 1;
		y = 1;
	}
	if(x == 1 && y == 2) {
		x = 1;
		y = 4;
	}
	if(x == 2 && y == 0) {
		x = 4;
		y = 7;
	}
	if(x == 2 && y == 1) {
		x = 4;
		y = 1;
	}
	if(x == 2 && y == 2) {
		x = 4;
		y = 4;
	}
	bool flag = 0;
	for(int i = 0; i < 3; ++i) {
		for(int j = 0; j < 3; ++j) {
			if(grid[x + i][y + j] == '.') {
				flag = 1;
				break;
			}
		}
	}
	if(flag) {
		for(int i = 0; i < 3; ++i) {
			for(int j = 0; j < 3; ++j) {
				if(grid[x + i][y + j] == '.') {
					grid[x + i][y + j] = '!';
				}
			}
		}	
	}
	else {
		for(int i = 1; i < 10; ++i) {
			for(int j = 1; j < 10; ++j) {
				if(grid[i][j] == '.') {
					grid[i][j] = '!';
				}
			}
		}
	}
	for(int i = 1; i < 10; ++i) {
		for(int j = 1; j < 10; ++j) {
			cout << grid[i][j];
			if(j%3 == 0) cout << " ";
		}
		cout << "\n";
		if(i%3 == 0) cout << "\n";
	}
	return 0;
}