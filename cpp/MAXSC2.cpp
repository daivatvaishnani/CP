#include <bits/stdc++.h>

using namespace std;

int a[707][707];

int main() {
	// freopen("in","r",stdin);
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		for(int i=0; i<n; ++i) for(int j=0; j<n; ++j) cin>>a[i][j];
		for(int row=0; row<n; ++row) sort(a[row],a[row]+n);
		long long ans=0;
		long long prevmax=1e9+1;
		bool possible=1;
		// for(int i=0; i<n; ++i) {
		// 	for(int j=0; j<n; ++j) cout<<a[i][j]<<" ";
		// 	cout<<"\n";
		// }
		for(int row=n-1; row>=0; --row) {
			int rowidx=n-1;
			while(rowidx>=0 && a[row][rowidx]>=prevmax) --rowidx;
			if(rowidx<0) {
				possible=0;
				break;
			}
			ans+=a[row][rowidx];
			prevmax=a[row][rowidx];
		}
		if(possible) cout<<ans<<"\n";
		else cout<<"-1\n";
	}
	return 0;
}