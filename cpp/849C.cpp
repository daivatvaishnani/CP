#include <bits/stdc++.h>

using namespace std;

int main() {
	// freopen("in","r",stdin);
	int k;
	cin >> k;
	int len=1,c=0;
	if(k==0) cout << 'a';
	while(k>0) {	
		int n = (sqrt(8*k+1)-1)/2;
		for(int i=0; i<=n; ++i) cout << (char)('a'+c);
		int rem = k-(n*n+n)/2;
		k = rem;
		++c;
	}
	return 0;
}