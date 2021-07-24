#include <bits/stdc++.h>

using namespace std;

#define PB push_back
#define MP make_pair
#define F first
#define S second

vector<pair<int,int> > arra, arrb;
vector<int> da,db;

bool cmp(pair<int,int> p1,pair<int,int> p2) {
	if(p1.F+p1.S==p2.F+p2.S) {
		if(p1.S==p2.S) return p1.F<p2.F;
		else return p1.S<p2.S;
	}
	else return p1.F+p1.S<p2.F+p2.S; 
}

inline void clear() {
	arra.clear(),arrb.clear();
	da.clear(),db.clear();
}

bool F(int i,int pa,int pb,bool mode) {
	if(!mode) return (arra[i].F>=pb && arra[i].S>=pa && !da[i]);
	else return (arrb[i].F>=pa && arrb[i].S>=pb && !db[i]);
}

string go(string a,string b,int pa,int pb) {
	// cout<<"pa:"<<pa<<" pb:"<<pb<<"\n";
	string ret="";
	if(pa>=a.size()) while(pb<b.size()) ret+=b[pb],++pb;
	else if(pb>=b.size()) while(pa<a.size()) ret+=a[pa],++pa;
	else {
		int ifa=0,ifb=0;
		while(ifa<arra.size() && !F(ifa,pa,pb,0)) ++ifa;
		while(ifb<arrb.size() && !F(ifb,pa,pb,1)) ++ifb;
		// cout<<"ifa:"<<ifa<<" ifb:"<<ifb<<"\n";
		if(arra[ifa].F-pb+arra[ifa].S-pa<arrb[ifb].F-pa+arrb[ifb].S-pb) {
			da[ifa]=1;
			while(pb<arra[ifb].F) ret+=b[pb],++pb;
			while(pa<arra[ifa].S) ret+=a[pa],++pa;
		}
		else {
			db[ifb]=1;
			while(pa<arrb[ifb].F) ret+=a[pa],++pa;
			while(pb<arrb[ifb].S) ret+=b[pb],++pb;
		}
		ret+=a[pa];
		ret+=b[pb];
		ret+=go(a,b,pa+1,pb+1);
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	int t;
	cin>>t;
	while(t--) {
		clear();
		int tn,tm;
		string ta,tb;
		cin>>tn>>tm>>ta>>tb;
		string a="",b="";
		a+=ta[0],b+=tb[0];
		int pa=0,pb=0;
		for(int i=1; i<tn; ++i) if(ta[i]!=a[pa]) a+=ta[i],++pa;
		for(int i=1; i<tm; ++i) if(tb[i]!=b[pb]) b+=tb[i],++pb;
		int n=a.size(),m=b.size();
		// cout<<ta<<" "<<tb<<"\n"<<a<<" "<<b<<"\n";
		for(int i=0; i<n; ++i) for(int j=0; j<m; ++j) if(b[j]==a[i]) arra.PB(MP(i,j)),da.PB(0);
		for(int i=0; i<m; ++i) for(int j=0; j<n; ++j) if(a[j]==b[i]) arrb.PB(MP(i,j)),db.PB(0);
		sort(arra.begin(),arra.end(),cmp);
		sort(arrb.begin(),arrb.end(),cmp);
		// cout<<"arra:\n";
		// for(auto p:arra) cout<<p.F<<" "<<p.S<<"\n";
		// cout<<"arrb:\n";
		// for(auto p:arrb) cout<<p.F<<" "<<p.S<<"\n";	
		string c1=go(a,b,0,0);
		int ans=0;
		for(int i=0;i<c1.size()-1;++i) if(c1[i]!=c1[i+1]) ++ans;
		cout<<++ans<<"\n"; 
		// fill(da.begin(),da.end(),0);
		// fill(db.begin(),db.end(),0);
		cout<<c1<<"\n";
	}
	return 0;
}