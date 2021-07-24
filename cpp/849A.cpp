#include <bits/stdc++.h>

using namespace std;

int main() {
	// freopen("in","r",stdin);
	int n;
	cin >> n;
	int A[n],odd=0,even=0;
	for(int i=0; i<n; ++i)
		cin >> A[i];
	if(n&1) {
		if(A[0]%2==0 || A[n-1]%2==0) cout << "No\n";
		else cout << "Yes\n";
	}
	else cout << "No\n";
	return 0;
}