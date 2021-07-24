#include <bits/stdc++.h>

using namespace std;

string go(int pa, int pb, string a, string b) {
	string add = "";
	// cout<<"pa:"<<pa<<" pb:"<<pb<<" ";
	if(pa>a.size()-1) {
		if(pb<b.size()) while(pb<b.size()) add+=b[pb++];
	}
	else if(pb>b.size()-1) {
		if(pa<a.size()) while(pa<a.size()) add+=a[pa++];
	}
	else {
		int one=0,two=0,tpa=pa,tpb=pb;
		while(tpb<b.size() && b[tpb++]!=a[tpa]) ++one;
		tpa=pa,tpb=pb;
		while(tpa<a.size() && a[tpa++]!=b[tpb]) ++two;
		// cout<<"one:"<<one<<" two:"<<two<<"\n";
		tpa=pa,tpb=pb;
		if(one==b.size()-tpb-1 && two==a.size()-pa-1) {
			if(a[tpa]<b[tpb]) add+=a[tpa]+b[tpb];
			else add+=b[tpb]+a[tpa];
			add+=go(++tpa,++tpb,a,b);
		}
		else if(one==b.size()-tpb-1 && two!=a.size()-tpa-1) {
			tpa=pa,tpb=pb;
			while(tpa<a.size() && b[tpb]!=a[tpa]) add+=a[tpa++];
			if(tpa<a.size()) add+=a[tpa];
			add+=go(++tpa,++pb,a,b);
		}
		else if(one!=b.size()-tpb-1 && two==a.size()-tpa-1) {
			tpa=pa,tpb=pb;
			while(tpb<b.size() && a[tpa]!=b[tpb]) add+=b[tpb++];
			if(tpb<b.size()) add+=b[tpb];
			add+=go(++pa,++tpb,a,b);
		}
		if(one>two) {
			tpa=pa,tpb=pb;
			while(tpa<a.size() && b[tpb]!=a[tpa]) add+=a[tpa++];
			if(tpa<a.size()) add+=a[tpa];
			add+=go(++tpa,++pb,a,b);
		}
		else {
			tpa=pa,tpb=pb;
			while(tpb<b.size() && a[tpa]!=b[tpb]) add+=b[tpb++];
			if(tpb<b.size()) add+=b[tpb];
			add+=go(++pa,++tpb,a,b);
		}
	}
	return add;
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	int t;
	cin>>t;
	while(t--) {
		int sa,sb,n,m,tot,pa,pb,pc;
		string a="",b="",c1="",c2="",ta,tb;
		cin>>n>>m>>ta>>tb;
		// cin>>ta>>tb;
		// n=ta.size(),m=tb.size();
		a=ta[0], b=tb[0];
		pa=0, pb=0;
		for(int i=1; i<n; ++i) if(ta[i]!=a[pa]) a+=ta[i], ++pa;
		for(int i=1; i<m; ++i) if(tb[i]!=b[pb]) b+=tb[i], ++pb;
		sa=a.size(), sb=b.size();
		tot = sa+sb;
		pa=0,pb=0,pc=0;
		int ans1=0,ans2=0;
		cout<<a<<" "<<b<<"\n";
		c1 = go(pa,pb,a,b);
		c2 = go(pb,pa,b,a);
		cout<<"\n"<<c1<<"\n";
		cout<<"\n"<<c2<<"\n";
		for(int i=0; i<c1.size()-1; ++i) if(c1[i]!=c1[i+1]) ++ans1;
		for(int i=0; i<c2.size()-1; ++i) if(c2[i]!=c2[i+1]) ++ans2;
		cout<<min(++ans1,++ans2)<<"\n";
	}
	return 0;
}