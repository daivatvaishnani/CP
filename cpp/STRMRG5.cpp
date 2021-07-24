#include <bits/stdc++.h>

using namespace std;

// vector<int> sa[5000],sb[5000];

int ans(string a, string b, int pa, int pb, char last) {
	int ret=0;
	if(pa>=a.size()) {
		while(pb<b.size()) {
			if(b[pb]!=last) ++ret;
			last=b[pb++];
		}
		return ret;
	}
	if(pb>=b.size()) {
		while(pa<a.size()) {
			if(a[pa]!=last) ++ret;
			last=a[pa++];
		}
		return ret;
	}
	if(a[pa]!=last) {
		if(b[pb]!=last)	ret+=1+min(ans(a,b,pa+1,pb,a[pa]),ans(a,b,pa,pb+1,b[pb]));
		else ret+=min(ans(a,b,pa+1,pb,a[pa])+1,ans(a,b,pa,pb+1,b[pb]));
	}
	else {
		if(b[pb]!=last) ret+=min(ans(a,b,pa+1,pb,a[pa]),ans(a,b,pa,pb+1,b[pb])+1);
		else ret+=min(ans(a,b,pa+1,pb,a[pa]),ans(a,b,pa,pb+1,b[pb]));
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("in","r",stdin)/*,freopen("out","w",stdout)*/;
	int t;
	cin>>t;
	while(t--) {
		// for(int i=0; i<5000; ++i) sa[i].clear(), sb[i].clear();
		int n,m;
		string ta,tb;
		cin>>n>>m>>ta>>tb;
		string a="",b="";
		a+=ta[0],b+=tb[0];
		int pa=0,pb=0;
		for(int i=0; i<n; ++i) if(ta[i]!=a[pa]) a+=ta[i],++pa;
		for(int i=0; i<m; ++i) if(tb[i]!=b[pb]) b+=tb[i],++pb;
		n=a.size(),m=b.size();
		// for(int i=0; i<n; ++i) for(int j=0; j<m; ++j) if(a[i]==b[j]) sa[i].push_back(j);
		// for(int i=0; i<n; ++i) for(int j=0; j<m; ++j) if(a[i]==b[j]) sa[i].push_back(j);
		cout << ans(a,b,0,0,'X') << "\n";
	}
	return 0;
} 