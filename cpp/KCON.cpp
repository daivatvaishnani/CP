#include <bits/stdc++.h>

using namespace std;

const long long maxn = 1e5 + 5;
long long arr[maxn], a[maxn];
long long meh[maxn];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	long long t;
	cin >> t;
	while(t--) {
		long long n, k;
		cin >> n >> k;
		for(long long i=0; i<n; ++i) cin >> a[i];
		for(long long i=0; i<n*k; ++i) arr[i] = a[i%n];
		meh[0] = arr[0];
		// for(long long i=0; i<n*k; ++i) cout << arr[i] << " ";
		// cout << "\n";
		for(long long i=1; i<n*k; ++i) {
			meh[i] = max(arr[i], meh[i-1] + arr[i]);
		}
		long long msf = meh[0];
		// for(long long i=0; i<n*k; ++i) cout << meh[i] << " ";
		// cout << "\n"; 
		for(long long i=1; i<n*k; ++i) msf = max(msf, meh[i]); 
		cout << msf << "\n";
	}
	return 0;
}