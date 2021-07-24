#include <bits/stdc++.h>
using namespace std;
int a[200][200];
int rsum[200], csum[200];
int t,n,k;
int main() {
	ios_base::sync_with_stdio(false);
	cin >> t;
	while(t--) {
		cin >> n >> k;
		for(int i=0; i<n; ++i) {
			for(int j=0; j<n; ++j) {
				cin >> a[i][j];
				rsum[i] += a[i][j];
				csum[j] += a[i][j];  
			}
		}

	}
}