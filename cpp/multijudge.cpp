#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> v;
ll n, k, d;

int main() {
	cin >> n >> k;
	for(int i=0; i<n; ++i) {
		cin >> d;	
		v.push_back(d);
	}
	sort(v.begin(), v.end());
	ll ans=0, maxd = k;
	for(int i=0; i<n; ++i) {
		if(v[i] > 2*maxd) {
			while(v[i] > 2*maxd) {
				++ans;
				maxd *= 2;
			}
		}
		maxd = max(maxd, v[i]);
 	}
	cout << ans << "\n";
}