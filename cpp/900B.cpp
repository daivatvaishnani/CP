#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	// freopen("in","r",stdin);
	// freopen("out", "w", stdout);
	bool flag = 0;
	int a, ta, b, c, q, r, cnt = 1;
	cin >> a >> b >> c;
	q = 0;
	if(a)
	a *= 10;
	while(1) {
		q = a/b;
		r = a - q*b;
		if(q == c) {
			flag = 1;
			break;
		}
		ta = 10*r;
		if(ta == a) {
			break;
		}
		else {
			a = ta;
		}
		++cnt;
		if(cnt > 10000000) {
			break;
		}	
	}
	if(flag) cout << cnt << "\n";
	else cout << "-1\n";
	return 0;
}