#include <bits/stdc++.h>

using namespace std;

int main() {
	// freopen("in","r",stdin);
	int t;
	cin >> t;
	while(t--) {
		int s1,s2,s3,s4;
		cin >> s1 >> s2 >> s3 >> s4;
		int a[] = {s1,s2,s3,s4};
		sort(a,a+4);
		if(a[1]==a[0] && a[2]==a[3]) cout<<"YES\n";
		else cout << "NO\n";
	}
	return 0;
}