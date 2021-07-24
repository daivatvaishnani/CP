#include <bits/stdc++.h>

using namespace std;

int main() {
	// freopen("in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long a1,a2;
	cin >> a1 >> a2;
	long long ans=0,add=0;
	while(1) {
		if(min(a1,a2)==a1) {
			if(a2&1) {
				if(a2==1)
					break;
				add = a2/2;
				ans += add;
				a2 = 1;
				a1 += add;
			}
			else {
				if(a2==2) {
					add = 1;
					a2 = 0;
				}
				else {
					add = a2/2 - 1;
					a2 = 2;
				}
				ans += add;
				a1 += add;
			}
		}
		else {
			if(a1&1) {
				if(a1==1)
					break; 
				add = a1/2;
				ans += add;
				a1 = 1;
				a2 += add;
			}
			else {
				if(a1==2) {
					add = 1;
					a1 = 0;
				}
				else {
					add = a1/2 - 1;
					a1 = 2;
				}
				ans += add;
				a2 += add;
			}
		}
		if(a1==0 || a2==0) break;
	}
	cout << ans << "\n";
	return 0;
}