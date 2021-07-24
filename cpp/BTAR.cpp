#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	// freopen("in","r",stdin);
	// freopen("out", "w", stdout);
	int t, n, val;
	cin >> t;
	while(t--) {
		cin >> n;
		int cnt[4] = {0};
		for(int i = 0; i < n; ++i) {
			cin >> val;
			val %= 4;
			++cnt[val];
		}
		int moves = 0;
		moves += cnt[2]/2;
		cnt[2] %= 2;
		int tmp = min(cnt[3], cnt[1]); 
		moves += tmp;
		cnt[3] -= tmp;
		cnt[1] -= tmp;
		if((cnt[1] + 2*cnt[2] + 3*cnt[3])%4 != 0) {
			cout << "-1\n";
			continue;
		}
		if(cnt[3] > 0) {
			if(cnt[2] > 0) {
				cnt[3] -= 2;
				cnt[2] = 0;
				moves += 2;
			}
			if(cnt[3]%4 == 0) {
				moves += 3*cnt[3]/4;
			}
			else {
				cout << "-1\n";
				continue;
			}
		}
		else if(cnt[1] > 0) {
			if(cnt[2] > 0) {
				cnt[1] -= 2;
				cnt[2] = 0;
				moves += 2;
			}
			if(cnt[1]%4 == 0) {
				moves += 3*cnt[1]/4;
			}
			else {
				cout << "-1\n";
				continue;
			}
		}
		cout << moves << "\n";
	}	
	return 0;
}