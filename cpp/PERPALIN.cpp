#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("in","r",stdin);
	freopen("out", "w", stdout);
	int t, n, p;
	cin >> t;
	while(t--) {
		cin >> n >> p;
		if(n < p) {
			cout << "impossible\n";
		}
		else if(n == p) {
			if(n < 3) {
				cout << "impossible\n";
			}
			else {
				string s(n - 2, 'b');
				s = "a" + s + "a";
				cout << s << "\n";
			}
		}
		else {
			if(p == 1) {
				cout << "impossible\n";
			}
			else if(p == 2) {
				if(n & 1) {
					char c = 'a';
					for(int i = 0; i < n; ++i) {
						cout << c;
						c = (c == 'a') ? 'b' : 'a';
					}
					cout << "\n";
				}
				else {
					cout << "impossible\n";
				}
			}
			else {
				string s(p - 2, 'b');
				s = "a" + s + "a";
				for(int i = 0; i < n / p; ++i) {
					cout << s;
				}
				cout << "\n";
			}
		}
	}
	return 0;
}