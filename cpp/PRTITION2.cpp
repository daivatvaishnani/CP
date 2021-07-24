#include <bits/stdc++.h>

using namespace std;

const long long maxn = 1e6+6;
bool in[maxn];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("in","r",stdin);
	// freopen("out","w",stdout);
	long long t;
	cin >> t;
	while(t--) {
		memset(in,false,sizeof(in));
		long long x, n;
		cin >> x >> n;
		long long s = n*(n+1)/2-x;
		if(n==2 || s&1) {
			cout << "impossible\n";
			continue;
		}
		long long need = s/2;
		long long got = 0;
		long long no = n;
		while(got < need && no >= 1) {
			if(no == x || no+x == need-got) {
				--no;
				continue;
			}
			if(need-got != x && need-got <= no) {
				in[need-got] = 1;
				break;				
			}
			got += no;
			in[no] = 1;
			--no;
		}
		// long long need = s/2;
		// long long st = 1;
		// if(st==x) ++st;
		// while(need > 0 && st<=n) {
		// 	if(need <= n && need != x) {
		// 		in[need] = 1;
		// 		break;
		// 	}
		// 	in[st] = 1;
		// 	need -= st;
		// 	st = st+1;
		// 	if(st == x) ++st;
		// }
		long long sc = 0;
		for(long long i=1; i<=n; ++i) if(in[i]) sc+=i;
		if(sc!=s/2) {
			cout << "impossible\n";
			continue;
		}
		for(long long i=1; i<=n; ++i) {
			if(i==x) cout << "2";
			else cout << in[i];
		}
		cout << "\n";
	}
	return 0;
}

/*

1 2 3 4 5 6 7 8 9 10 11 66
0 0 0 0 0 0 0 1 1 2  1	56 8
5 7
32 


*/