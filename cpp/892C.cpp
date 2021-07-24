#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e7 + 7;
vector<int> a;

inline int GCD(int a, int b) {
	return __gcd(a, b);
}

int GCCD(int a, int b) {
	// REP1
	int m1 = 0;
	while(GCD(a, b) != 1) {
		if(GCD(a, GCD(a, b)) == GCD(a, b)) {
			m1 = maxn;
			break;
		}
		++m1;
		b = GCD(a, b);
	}
	// REP2
	int m2 = 0;
	while(GCD(a, b) != 1) {
		if(GCD(GCD(a, b), b) == GCD(a, b)) {
			m2 = maxn;
			break;
		}
		++m2;
		a = GCD(a, b);
	}

	return(min(m1, m2));
} 

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("in","r",stdin);
	freopen("out", "w", stdout);
	int n, val;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> val;
		a.push_back(val);
	}
	int sa = a.size();
	int gCD = a[0];
	for(int i = 1; i < sa; ++i) {
		gCD = GCD(gCD, a[i]);
	}
	if(gCD != 1) {
		cout << "-1\n";
	}
	else {
		cout << "Possible\n";
		for(int i = 0; i < sa - 1; ++i) {
			cout << a[i] << " " << a[i + 1] << " -> ";
			cout << GCCD(a[i], a[i + 1]) << "\n";
		}
	}
	return 0; 
}