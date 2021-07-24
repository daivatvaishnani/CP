#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	// freopen("in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	int k;
	cin >> s;
	cin >> k;
	int szs = s.size();
	if(szs < k) cout << "impossible\n";
	else {
		if(k>26) cout << "impossible\n";   
		else {
			int occ[26];
			for(int i=0; i<26; ++i) occ[i]=0;
			for(int i=0; i<szs; ++i) ++occ[(int)(s[i]-97)];
			int dif=0;
			for(int i=0; i<26; ++i) if(occ[i]) ++dif;
			if(dif >= k) cout << "0\n";
			else {
				int ans=0,temp;
				sort(occ,occ+26);
				for(int i=0; i<26; ++i) {
					if(occ[i]>1) {
						temp=min(occ[i]-1,k-dif);
						ans+=temp;
						dif+=temp;
					}
					if(dif>=k) break;
				}
				cout << ans << "\n";
			}
		}	
	}
}