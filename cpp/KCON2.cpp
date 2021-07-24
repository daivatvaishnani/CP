#include <bits/stdc++.h>

using namespace std;

const long long maxn = 1e5 + 5;
long long arr[3*maxn], a[maxn];
long long meh[3*maxn];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("in","r",stdin);
	// freopen("out","w",stdout);
	long long t;
	cin >> t;
	while(t--) {
		long long n, k;
		cin >> n >> k;
		for(long long i=0; i<n; ++i) cin >> a[i];
		for(long long i=0; i<3*n; ++i) arr[i] = a[i%n];
		meh[0] = arr[0];
		for(long long i=1; i<3*n; ++i) meh[i] = max(arr[i], meh[i-1] + arr[i]);
		long long msf1 = meh[0], msf2 = meh[0], msf3 = meh[0];
		for(long long i=1; i<n; ++i) msf1 = max(msf1, meh[i]); 
		for(long long i=1; i<2*n; ++i) msf2 = max(msf2, meh[i]);
		for(long long i=1; i<3*n; ++i) msf3 = max(msf3, meh[i]);
		if(k==1) cout << msf1 << "\n";
		else cout << msf2 + (k-2)*abs(msf3 - msf2) << "\n";			
	}
	return 0;
}