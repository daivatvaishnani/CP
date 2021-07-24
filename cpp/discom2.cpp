#include <bits/stdc++.h>
using namespace std;
int a[200][200];
int rsum[200], csum[200];
#define row row
#define sum first
int t,n,k,ans,rmin,cmin;
void reset() {
	for(int i=0; i<n; ++i) {
		rsum[i] = 0, csum[i] = 0;
	}
}
int findrmin() {
	int idx = 0;
	for(int i=1; i<n; ++i) {
		if(rsum[i] < rsum[idx])
			idx = i;
	}
	return idx;
}
int findcmin() {
	int idx = 0;
	for(int i=1; i<n; ++i) {
		if(csum[i] < csum[idx])
			idx = i;
	}
	return idx;
}
void incrsum() {
	for(int i=0; i<n; ++i) {
		++rsum[i];
	}
}
void inccsum() {
	for(int i=0; i<n; ++i) {
		++csum[i];
	}
}
int main() {
	freopen("in","r",stdin); freopen("out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin >> t;
	while(t--) {
		reset();
		cin >> n >> k;
		for(int i=0; i<n; ++i) {
			for(int j=0; j<n; ++j) {
				cin >> a[i][j];
				rsum[i] += a[i][j];
				csum[j] += a[i][j];  
			}
		}
		ans = 0;
		int rcount=0,ccount=0;
		while(k--) {
			int rmin = findrmin();
			int cmin = findcmin();
			if(rsum[rmin] < csum[cmin]) {
				ans += rsum[rmin];
				rsum[rmin] += n;
				inccsum();
			}
			else {
				ans += csum[cmin];
				csum[cmin] += n;
				incrsum();
			}
		}
		cout << ans << "\n";
	}
}