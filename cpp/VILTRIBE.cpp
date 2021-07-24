#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("in","r",stdin);
	freopen("out", "w", stdout);
	int t, ca, cb;
	int z = -1, lp = -1;
	string s;
	cin >> t;
	while(t--) {
		cin >> s;
		int szs = s.size();
		ca = 0; cb = 0;
		z = -1, lp = -1;
		for(int i = 0; i < szs; ++i) {
			if(s[i] == 'A') {
				++ca;
				if(z == 0) {
					ca += i - lp - 1;
				}
				z = 0;
				lp = i;
			}
			else if(s[i] == 'B') {
				++cb;
				if(z == 1) {
					cb += i - lp - 1;
				}
				z = 1;
				lp = i;
			}
		}
		cout << ca << " " << cb << "\n";
	}	
	return 0;
}