#include <bits/stdc++.h>

using namespace std;

const long long M = 1000000007;

long long power(long long a, long long b) {
	long long ans = 1;
	a = a % M;
	while(b > 0) {
		if(b & 1) {
			ans = (ans * a) % M;
		}
		a = (a * a) % M;
		b = b / 2;
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	// freopen("in","r",stdin);
	string s;
	cin >> s;
	long long szs = s.size();
	long long ans = 0;
	for(int i = 1; i <= szs; ++i) {
		ans += (1LL * ((long long)(s[i-1] - 'a')) * power(26, szs - i)) % M;
	}
	ans = (ans + 1) % M;
	cout << ans << "\n";
	return 0;
}