#include <bits/stdc++.h>

using namespace std;

int main() {

	freopen("in","r",stdin);

	int n, k, given = 0, have = 0, days = 0, add = 0, ans = -1;

	cin >> n >> k;

	while(days < n) {
		cin >> add;
		++days;
		if(ans == -1) {
			have += add;
			if(have > 8) {
				given += 8;
				have -= 8;
			}
			else {
				given += have;
				have = 0;
			}
			if(given >= k) {
				ans = days;
			} 
		}
	}

	cout << ans << "\n";

	return 0;
	
}