#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int arr[700][700];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) {
		memset(arr,-1,sizeof(arr));
		int n;
		cin >> n;
		for(int i=0; i<n; ++i) {
			for(int j=0; j<n; ++j) {
				cin >> arr[i][j];
			}
		}
		for(int i=0; i<n; ++i) {
			sort(arr[i], arr[i]+n);
		}
		long long sum = 0;
		bool p = 1;
		int pmax = (int)1e9+1; 
		int sq = n;
		while(sq--) {
			int id = n-1;
			while(arr[sq][id] >= pmax) {
				--id;
				if(id<0) break;
			}
			if(id<0) {
				p = 0;
				break;
			}
			sum += 1LL*arr[sq][id];
			pmax = arr[sq][id];
		}
		if(p) cout << sum << "\n";
		else cout << "-1\n";
	}
	return 0;
}