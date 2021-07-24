#include <bits/stdc++.h>

using namespace std;

int main() {
	// freopen("in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T,D[9],TD[9],u,t;
	string N;
	cin >> T;
	while(T--) {
		for(int i=0; i<10; ++i) D[i]=0, TD[i]=0;
		cin >> N;
		for(int i=0; i<N.size(); ++i) ++D[(int)(N[i]-'0')], ++TD[(int)(N[i]-'0')];
		for(int i=65; i<=90; ++i) {
			u = i%10;
			t = (i/10)%10;
			if(TD[u]>0) {
				--TD[u];
				if(TD[t]>0) cout << (char)i;
				TD[u]=D[u];
			}
		}
		cout << "\n";
	}
	return 0;
}