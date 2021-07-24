#include <bits/stdc++.h>
using namespace std;
int t,n,d1,d2;
int main() {
	// freopen("in","r",stdin); freopen("out","w",stdout);
	std::ios_base::sync_with_stdio(false);
	cin>>t;
	while(t--) {
		cin>>n;
		cout<<n<<"\n";
		for(int i=1; i<=n; ++i) {
			cout<<n<<"\n";
			for(int j=1; j<=n; ++j) {
				d1 = (i+j-1);
				if(d1>n) d1%=n;
				d2 = d1+1;
				if(d2>n) d2%=n;
				cout<<j<<" "<<d1<<" "<<d2<<"\n";
			}
		}		
	}
}
