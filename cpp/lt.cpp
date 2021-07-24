#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,a,b,n;
int main() {	
	ios_base::sync_with_stdio(false);
	freopen("in","r",stdin); freopen("out","w",stdout);
	cin >> t;
	while(t--) {
		cin >> a >> b >> n;
		if(n==1) {
			cout << max(2*a,b) / min(2*a,b) << "\n";
			continue;
		}
		if(n & 1) {
			cout << max(2*(n-1)*a,(n-1)*b) / min(2*(n-1)*a,(n-1)*b) << "\n"; 
			continue;
		}
		cout << max(n*a,n*b) / min(n*a,n*b) << "\n"; 
	}
	return 0;
}