#include <bits/stdc++.h>

using namespace std;

const int maxn = 105;
string c[maxn], a[maxn];

string make_string(char start, int length) {
	string s = "";
	while(length--) {
		s += start;
		start = (start == 'R') ? 'G' : 'R';
	}
	return s;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	// freopen("in", "r", stdin);
	// freopen("out", "w", stdout);
	int t;
	cin >> t;
	while(t--) {
		int n, m;
		cin >> n >> m;
		for(int i = 0; i < n; ++i) {
			cin >> c[i];
		}
		char start = 'R';
		for(int i = 0; i < n; ++i) {
			a[i] = make_string(start, m);
			start = (start == 'R') ? 'G' : 'R';
		}
		int ans1 = 0;
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j) {
				if(c[i][j] != a[i][j]) {
					ans1 += (c[i][j] == 'R') ? 5 : 3;
				}
			}
		}
		int ans2 = 0;
		start = 'G';
		for(int i = 0; i < n; ++i) {
			a[i] = make_string(start, m);
			start = (start == 'R') ? 'G' : 'R';
		}
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j) {
				if(c[i][j] != a[i][j]) {
					ans2 += (c[i][j] == 'R') ? 5 : 3;
				}
			}
		}
		cout << min(ans1, ans2) << "\n"; 
	}
	return 0;
}
