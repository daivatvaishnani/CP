#include <bits/stdc++.h>

using namespace std;

#define msg(x) cout << #x << " : " << x << "\n"
#define For(i, x, y) for(int i = x; i <= y; ++i)
#define forn(i, n) rep(i, 0, n - 1)
#define Forr(i, x, y) for(int i = y; i >= x; --i)
#define forrn(i, n) rrep(i, 0, n - 1)
#define pi acos(-1)
#define GCD(x, y) __gcd(x, y)

const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;

int a[maxn], pre[maxn];
vector<pair<int, int> > tmp[maxn];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("in","r",stdin); freopen("out", "w", stdout);
	cout << mod << "\n";
	int t, n, d;
	while(t--) {
		cin >> n >> d;
		forn(i, n) cin >> a[i];
		pre[0] = a[0];
		For(i, 1, n) pre[i] += pre[i - 1];
		forn(i, n) {
			if()
		}
	}
	return 0;
}