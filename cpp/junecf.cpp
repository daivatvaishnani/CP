#include <bits/stdc++.h>
using namespace std;
int t,size,u,d;
string s;
int main() {
	// freopen("in","r",stdin); freopen("out","w",stdout);
	cin>>t;
	while(t--) {
		cin>>s;
		size = s.size();
		u=0,d=0;
		if(s[0]=='U') ++u;
		else	++d;
		for(int i=1; i<size; ++i) {
			if(s[i]!=s[i-1]) {
				if(s[i]=='U') ++u;
				else ++d;
			}	
		}
		d<u ? cout<<d<<"\n" : cout<<u<<"\n";
	}
}
