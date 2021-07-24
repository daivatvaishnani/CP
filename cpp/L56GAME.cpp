#include <bits/stdc++.h>

using namespace std;

int mods[2]; 

int main() {
	int T;
	cin >> T;
	while(T--) {
		memset(mods, 0, sizeof(mods));
		int N;
		cin >> N;
		for (int i = 0; i < N; ++i) {
			int a;
			cin >> a;
			++mods[a % 2];
		}
		if(mods[1] & 1) {
			cout << "2\n";
		}
		else {
			cout << "1\n";
		}
	}
	return 0;
}