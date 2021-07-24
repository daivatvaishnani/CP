#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int> > va,vb;

string go(string a, string b, int n, int m, int pa, int pb) {
	string ret="";
	if(pa>=n && pb<m) {
		while(pb<m) ret+=b[pb++];
		return ret;
	}
	if(pa<n && pb>=m) {
		while(pa<n) ret+=a[pa++];
		return ret;
	}
	if(pa>=n && pb>=m) return ret;
	int one=0,two=0,tpa=pa,tpb=pb;
	while(tpb<m && b[tpb]!=a[tpa]) ++tpb,++one;
	tpa=pa,tpb=pb;
	while(tpa<n && a[tpa]!=b[tpb]) ++tpa,++two;
	if(one==m-pb-1 && two==n-pa-1) {
		if(a[pa]<b[pb]) ret+=a[pa]+b[pb]+go(a,b,n,m,pa+1,pb+1);
	}
	if(one>two)	ret+=a[pa]+go(a,b,n,m,pa+1,pb);
	else ret+=b[pb]+go(a,b,n,m,pa,pb+1);
	return ret;
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	int t;
	cin>>t;
	while(t--) {
		int tn,tm;
		string ta,tb;
		cin>>tn>>tm>>ta>>tb;
		cout<<ta<<" "<<tb<<"\n";
		string a="",b="";
		a+=ta[0],b+=tb[0];
		int pa=0,pb=0;
		for(int i=1; i<tn; ++i) if(ta[i]!=a[pa]) a+=ta[i],++pa;
		for(int i=1; i<tm; ++i) if(tb[i]!=b[pb]) b+=tb[i],++pb;	
		int n=a.size(),m=b.size();
		cout<<a<<" "<<b<<"\n";
		string c1=go(a,b,n,m,0,0);
		string c2=go(b,a,m,n,0,0);
		int ans1=0,ans2=0;
		for(int i=0; i<c1.size()-1; ++i) if(c1[i]!=c1[i+1]) ++ans1;
		for(int i=0; i<c2.size()-1; ++i) if(c2[i]!=c2[i+1]) ++ans2;
		cout<<c1<<"\n"<<c2<<"\n";
		cout<<min(++ans1,++ans2)<<"\n";
	}
	return 0;
}