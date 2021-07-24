#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+55;
ll t,n,q,ans,x,k;
int a[N],sum[N],pre[N];
inline bool check(int m, int temp, int len) {
	return (len*m - sum[temp] + sum[temp-m] <= temp-m+1);
}
int bsx(int l, int r, int key) {
	if(key < a[l])
		return -1;
	int m;
	while(r-l > 1) {
		m = l + (r-l)/2;
		if(a[m] <= key)
			l = m;
		else
			r = m;
	}
	return l;
}
int solve(int l, int r, int len) {
	int m;
	int temp = r;
	while(r-l > 1) {
		cout<<l<<" "<<m<<" "<<r<<"\n";
		m = l + (r-l)/2;
		if(check(m,temp,len))
			l = m;
		else
			r = m;
	}
	return l;
}
int main() {
	freopen("in","r",stdin);
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	while(t--) {
		cin >> n >> q;
		for(int i=0; i<n; ++i) {
			cin >> a[i];
		}
		sort(a, a+n);
		sum[0] = a[0];
		for(int i=0; i<n; ++i) {
			sum[i] = sum[i-1] + a[i];
		}
		for(int i=0; i<n ;++i) {
			cout<<a[i]<<" ";
		}cout<<"\n";
		for(int i=0; i<n ;++i) {
			cout<<sum[i]<<" ";
		}cout<<"\n";		
		while(q--) {
			cin >> k;
			x = bsx(0,n,k);
			ans = solve(0,x+1,k);
			cout <<k<<" "<<x<<" "<< ans << "\n";
		}
	}
}