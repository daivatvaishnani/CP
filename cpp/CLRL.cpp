#include <bits/stdc++.h>

using namespace std;

std::vector<int> rv;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("in","r",stdin);
	freopen("out", "w", stdout);
	int t, n, r, rr;
	cin >> t;
	bool ok;
	// int prev = -1;
	int sign = 0;
	int mx, mn;
	while(t--) {
		rv.clear();
		ok = 1;
		cin >> n >> r;
		for(int i = 0; i < n; ++i) {
			cin >> rr;
			rv.push_back(rr);
		}
		if(n <= 2) {
			cout << "YES\n";
			continue;
		}
		sign = rv[0] < r ? 1 : -1;
		for(int i = 1; i < n; ++i) {
 			if(sign == 1) {
 				if(rv[i] < rv[i - 1]) {
 					ok = 0;
 					break;
 				}
 				else if(i > 1) {
 					sign = rv[i - 2] < r ? 1 : -1;
 					if(sign == -1 && rv[i] > rv[i - 2]) {
 						ok = 0;
 						break;
 					}
 				}
				sign = rv[i] < r ? 1 : -1;
 			}
 			else {
 				if(rv[i] > rv[i - 1]) {
 					ok = 0;
 					break;
 				}
 				else if(i > 1) {
 					sign = rv[i - 2] < r ? 1 : -1;
 					if(sign == 1 && rv[i] < rv[i - 2]) {
 						ok = 0;
 						break;
 					}
 				}
				sign = rv[i] < r ? 1 : -1;
 			}
		}
		if(ok) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	} 	
	return 0;
}