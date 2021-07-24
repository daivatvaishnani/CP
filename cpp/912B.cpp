#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	// freopen("in","r",stdin);
	ll n,k;
	cin>>n>>k;
	if(k==1) cout<<n<<"\n";
	else {		
		ll ans=1;
		while(ans<=n) ans<<=1;
		cout<<ans-1<<"\n";
	}
	return 0;
}