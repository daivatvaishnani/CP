#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6+7;
ll t,n,val,temp;
ll c[N], w[N], found[N], sum[N];
vector<ll> v;
int main() {	
	ios_base::sync_with_stdio(false);
	freopen("in","r",stdin); freopen("out","w",stdout);
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i=0; i<=n; ++i) {
			c[i] = 0, w[i] = 0, found[i] = 0, sum[i] = 0;
		}
		for(int i=1; i<=n; ++i) {
			cin >> c[i];
		}
		for(int i=1; i<=n; ++i) {
			cin >> w[i];
		}
		sum[1] = w[1];
		for(int i=2; i<=n; ++i) {
			sum[i] = sum[i-1] + w[i];
		}
		temp = 0;
		for(int i=1; i<=n; ++i) {
			if(found[c[i]] == 0) {
				temp = temp + w[i];
				found[c[i]] = i;
				continue; 
			}
			v.push_back(temp);
			temp = sum[i] - sum[found[c[i]]];
			found[c[i]] = i;
		}
		v.push_back(temp);
		temp = 0;
		for(int i=0; i<v.size(); ++i) {
			if(temp < v[i])
				temp = v[i];
		}
		cout << temp << "\n";
	} 
	return 0;
}