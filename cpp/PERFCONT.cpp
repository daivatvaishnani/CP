#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("in","r",stdin);
	freopen("out", "w", stdout);
	int t, n, p, cw, h, ni;
	cin >> t;
	while(t--) {
		cw = 0, h = 0;
		cin >> n >> p;
		while(n--) {
			cin >> ni;
			if((ni >= p/2 && p%2 == 0) || (ni > p/2 && p%2 != 0)) {
				++cw;
			}
			else if((ni <= p/10 && p%10 == 0) || (ni <= p/10 + 1 && p%10 != 0))
				++h;  
		}
		if(cw == 1 && h == 2)
			cout << "yes\n";
		else 
			cout << "no\n";
	}
	return 0;
}