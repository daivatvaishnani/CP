#include <bits/stdc++.h>

using namespace std;

vector<long long> p, np, moves;

inline bool ifp(long long num) {
	return (sqrt(num) == (long long) sqrt(num));
}

inline long long minm(long long num) {
	if(ifp(num)) {
		return 0;
	}
	long long msr = sqrt(num);
	long long n1 = num - msr * msr;
	long long n2 = (msr + 1) * (msr + 1) - num;
	return(min(n1, n2));
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	// freopen("in","r",stdin);
	// freopen("out", "w", stdout);
	long long n, v, num, move, nps = 0;
	cin >> n;
	long long tn = n;
	while(tn--) {
		cin >> num;
		move = minm(num);
		if(move == 0) {
			if(num == 0) {
				move = 2;
			}
			else move = 1;
			p.push_back(move);
			++nps;
		}
		else {
			np.push_back(move);
		}
	}
	sort(np.begin(), np.end());
	sort(p.begin(), p.end());
	if(nps < n/2) {
		long long ans = 0, i = 0;
		while(nps < n/2) {
			ans += np[i++];
			++nps;
		}
		cout << ans << "\n";
	}
	else if(nps > n/2) {
		long long ans = 0, i = 0;
		while(nps > n/2) {
			ans += p[i++];
			--nps;
		}
		cout << ans << "\n";
	}
	else {
		cout << "0\n";
	}
	return 0;
}