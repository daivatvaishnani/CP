#include <bits/stdc++.h>
using namespace std;
int main() {
	// freopen("in","r",stdin);
	string s;
	cin >> s;
	vector<int> Vec;
	int sf=0, sl=0, diff=0, ans=0;
	for(int i=0; i<3; ++i) Vec.push_back((int)(s[i]-'0')), sf += (int)(s[i]-'0');
	for(int i=3; i<6; ++i) Vec.push_back((int)(s[i]-'0')), sl += (int)(s[i]-'0');
	if(sf == sl) ans=0;
	else if(sf > sl) {
		diff = sf-sl, ans = 0;
		for(int i=3; i<6; ++i) Vec[i] = 9-Vec[i];
		sort(Vec.begin(), Vec.end());
		for(int i=5; i>=0 && diff>0; --i) diff -= Vec[i], ++ans;  
	}
	else {
		diff = sl-sf, ans = 0;
		for(int i=0; i<3; ++i) Vec[i] = 9-Vec[i];
		sort(Vec.begin(), Vec.end());
		for(int i=5; i>=0 && diff>0; --i) diff -= Vec[i], ++ans;
	}
	cout << ans << "\n";
}