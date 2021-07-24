#include <bits/stdc++.h>

using namespace std;

const long long maxn = 1e6+6;
bool team[maxn];

int main() {
	long long t;
	cin >> t;
	while(t--) {
		memset(team,false,sizeof(team));
		long long x, n;
		cin >> x >> n;
		long long sum = n*(n+1)/2-x;
		if(n==2 || sum&1) {
			cout << "impossible\n";
			continue;
		}
		long long want = sum/2;
		long long have = 0;
		long long index = n;
		while(have < want && index >= 1) {
			if(index == x || index+x == want-have) {
				--index;
				continue;
			}
			if(want-have != x && want-have <= index) {
				team[want-have] = 1;
				break;				
			}
			have += index;
			team[index] = 1;
			--index;
		}
		long long sc = 0;
		for(long long i=1; i<=n; ++i) if(team[i]) sc+=i;
		if(sc!=sum/2) {
			cout << "impossible\n";
			continue;
		}
		for(long long i=1; i<=n; ++i) {
			if(i==x) cout << "2";
			else cout << team[i];
		}
		cout << "\n";
	}
	return 0;
}