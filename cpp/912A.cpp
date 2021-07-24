#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	// freopen("in","r",stdin);
	ll a,b;
	cin>>a>>b;
	ll y,g,bl;
	cin>>y>>g>>bl;
	ll br=g+3*bl;
	ll yr=2*y+g;
	ll ans=0;
	if(yr>a) ans+=yr-a;
	if(br>b) ans+=br-b;
	cout<<ans<<"\n"; 
	return 0;
}