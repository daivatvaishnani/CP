#include <bits/stdc++.h>

using namespace std;

multiset<long long> S;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("in","r",stdin);
	long long N, Q, val, type, x;
	cin >> N >> Q;
	S.clear();
	for(int i = 0; i < N; ++i) {
		cin >> val;
		S.insert(val); 
	}
	for(int i = 0; i < Q; ++i) {
		cin >> type >> x;
		if(type == 1)
			S.insert(x);
		else
			cout << (S.lower_bound(x) - S.begin())<< "\n";
	}
	return 0;
}