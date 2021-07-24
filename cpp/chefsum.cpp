#include <bits/stdc++.h>

using namespace std;

int main() {
	// freopen("in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T,N,mtn,cv,ans;
	cin >> T;
	while(T--) {
		mtn=1000005, ans=1;
		cin >> N;
		for(int i=1; i<=N; ++i) {
			cin >> cv;
			if(cv < mtn) {
				mtn = cv;
				ans = i;
			}
		}
		cout << ans << "\n";
	}
}