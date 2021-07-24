#include <bits/stdc++.h>

using namespace std;

vector<int> v;
long long D = 1, flag = 0;

int ans(int x) {
	// if(v.size() <= 2) {
	// 	return floor(floor(x / v[0]) / v[1]);
	// }
	// for(int i = 0; i < v.size(); ++i) {
	// 	x = floor(x / v[i]);
	// 	if(x <= 0) {
	// 		break;
	// 	}
	// }
	if(flag == 1) return 0;
	else return floor(x / D);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("in","r",stdin);
	freopen("out", "w", stdout);
	int t;
	cin >> t;
	while(t--) {
		v.clear();
		int n, q, val, d, x;
		cin >> n >> q;
		while(n--) {
			cin >> d;
			v.push_back(d);
		}
		D = 1, flag = 0;
		for(int i = 0; i < v.size(); ++i) {
			D *= v[i];
			if(D > 1e9) {
				flag = 1;
				break;
			} 
		}
		while(q--) {
			cin >> x;
			cout << ans(x) << " ";
		}
		cout << "\n";
	}
	return 0;
}