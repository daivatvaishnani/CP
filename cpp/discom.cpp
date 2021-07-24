#include <bits/stdc++.h>
using namespace std;
int a[200][200];
int rsum[200], csum[200];
map<int,int> rs, cs;
#define row row
#define sum first
int t,n,k,ans,rmin,cmin;
void reset() {
	for(int i=0; i<n; ++i) {
		rsum[i] = 0, csum[i] = 0;
	}
	rs.clear();
	cs.clear();
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
		for(int i=0; i<n; ++i) {
			rs.insert(make_pair(rsum[i],i));
			cs.insert(make_pair(csum[i],i));
		}
		// for(auto i=rs.begin(); i!=rs.end(); ++i) {
		// 	cout << (*i).row << " " << (*i).sum << "\n";
		// }
		// for(auto i=cs.begin(); i!=cs.end(); ++i) {
		// 	cout << (*i).row << " " << (*i).sum << "\n";
		// }
		ans = 0;
		int rcount=0,ccount=0;
		while(k--) {
			auto rmin = (*rs.begin());
			auto cmin = (*cs.begin());
			if((rmin.sum + rcount) < (cmin.sum + ccount)) {
				int temp = rmin.sum + rcount; 
				ans += temp;
				rs[rmin.row] += n;
				++ccount;
				cout << temp << "\n";
			}
			else {
				int temp = cmin.sum + ccount;
				ans += temp;
				cs[cmin.row] += n;
				++rcount;
				cout << temp << "\n";
			}
			cout << rmin.sum << " " << rcount << " " << cmin.sum << " " << ccount << "\n";
		}
		cout << ans << "\n";
	}
}