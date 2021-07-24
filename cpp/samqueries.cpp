#include <bits/stdc++.h>

using namespace std;

typedef vector<long long> vll;

void insertv(vll &v, long long value) {
    vll::iterator it = lower_bound(v.begin(), v.end(), value);
    v.insert(it, value);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("in","r",stdin);
	vll V;
	long long N, Q, val, type, x;
	cin >> N >> Q;
	for(int i = 0; i < N; ++i) {
		cin >> val;
		V.push_back(val);
	}
	sort(V.begin(), V.end());
	for(int i = 0; i < Q; ++i) {
		cin >> type >> x;
		// for(int i = 0; i < V.size(); ++i) cout << V[i] << " ";
			// cout << "\n";
		if(type == 1) {
			insertv(V, x);
		}
		else {
			cout << lower_bound(V.begin(), V.end(), x) - V.begin() << "\n";
		}
	}
	return 0;
}