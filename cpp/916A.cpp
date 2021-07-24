#include <bits/stdc++.h>

using namespace std;

int main() {
	// freopen("in", "r", stdin);
	int x, h, m;
	cin >> x >> h >> m;
	int ans = 0;
	while(1) {
		if(m % 10 == 7 || m / 10 == 7 || h % 10 == 7 || h / 10 == 7) {
			break;
		}
		m -= x;
		if(m < 0) { 
			m += 60;
			h -= 1;
			if(h < 0) {
				h += 24;
			}
		}
		++ans;
	}
	cout << ans << "\n";
	return 0;
}