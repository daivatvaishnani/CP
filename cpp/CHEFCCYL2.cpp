#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;

vll tmp, cd, precd;
vector<pll> vp;
vector<vll> pre;

int t, n, q, a, w, n1, n2, c1, c2;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("in","r",stdin);
	freopen("out", "w", stdout);
	cin >> t;
	while(t--) {
		cin >> n >> q;
		for(int i = 0; i < n; ++i) {
			tmp.clear();
			cin >> a;
			for(int i = 0; i < a; ++i) {
				cin >> w;
				tmp.push_back(w);
			}
			if(tmp.size() > 1) {
				if(tmp.size() == 2) {
					tmp[0] = tmp[1] = min(tmp[0], tmp[1]);
				}
				else {

				}
 			}
		}
	}
	return 0;
}
