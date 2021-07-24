#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("in","r",stdin);
	// freopen("out","w",stdout);
	int t;
	cin>>t;
	while(t--) {
		int n,m;
		string a,b;
		cin>>n>>m>>a>>b;
		string ma="",mb="";
		ma+=a[0],mb+=b[0];
		int pma=0,pmb=0;
		for(int i=1; i<n; ++i) if(ma[pma]!=a[i]) ma+=a[i],++pma;
		for(int i=1; i<m; ++i) if(mb[pmb]!=b[i]) mb+=b[i],++pmb;
		cout<<ma<<"\n"<<mb<<"\n";
		string c1="",c2="";
		pma=0,pmb=0;
		while(pma<ma.size()) {
			while(pmb<mb.size() && mb[pmb]!=ma[pma]) c1+=mb[pmb++];
			c1+=ma[pma++];
		}
		string c2="";
		pma=0,pmb=0;
		while(pmb<mb.size()) {
			while(pma<ma.size() && ma[pma]!=mb[pmb]) c2+=ma[pma++];
			c2+=mb[pmb++];
		}
		int ans1=0,ans2=0;
		for(int i=0; i<c1.size()-1; ++i) if(c1[i]!=c1[i+1]) ++ans1;
		for(int i=0; i<c2.size()-1; ++i) if(c2[i]!=c2[i+1]) ++ans2;
		cout<<c1<<" "<<c2<<"\n";
		cout<<min(++ans1,++ans2)<<"\n";
	}
	return 0;
}