#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;
vector<int> a;
pair<int, int> ap[maxn];
int sel[maxn];
vector<pair<int, int> > vp;
int lis[maxn], lds[maxn];

bool cmp(pair<int, int> p1, pair<int, int> p2) {
	if(p1.second == p2.second) {
		return p1.first < p2.first;
	}
	else {
		return p1.second > p2.second;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("in","r",stdin);
	freopen("out", "w", stdout);
	int n, val;
	cin >> n;
	while(n--) {
		cin >> val;
		a.push_back(val);
	}
	n = a.size();
	if(n == 1) {
		cout << a[0] << "\n";
	}
	else if(n == 2) {
		cout << min(a[0], a[1]) << "\n";
	}
	else {
		int lish = 1;
		lis[0] = 1; 
		for(int i = 1; i < n; ++i) {
			if(a[i] > a[i - 1]) {
				lis[i] = max(lish + 1, lis[i - 1]);
				++lish;				
			}
			else {
				lish = 0;
			}
		}
		for(int i = 0; i < n; ++i) {
			cout << lis[i] << " ";
		}
		cout << "\n";
		for(int i = 0; i < n; ++i) {
			if(i > 0 && a[i - 1] > a[i]) {
				sel[i] = 1;
			}
			if(i < n - 1 && a[i + 1] < a[i]) {
				sel[i] = 1;
			}
		}
	}
	return 0;
}



		// int pc = 0, c = 0;
		// for(int i = 0; i < n - 1;) {
		// 	int ti = i;
		// 	if(a[i + 1] < a[i]) {
		// 		cout << pc << "\n";
		// 		c = 1;
		// 		++i;
		// 		if(i > 1 && a[i - 2] < a[i]) c += pc - 1;
		// 		while(i < n - 1 && a[i + 1] > a[i]) {
		// 			++i, ++c;
		// 		}
		// 		vp.push_back({a[ti], max(c, pc)});
		// 		pc = max(c, pc);
		// 	}
		// 	else {
		// 		++pc;
		// 		++i;
		// 	}
		// }
		// if(vp.size() == 0) {
		// 	cout << a[0] << "\n";
		// }
		// else {
		// 	sort(vp.begin(), vp.end(), cmp);
		// 	for(int i = 0; i < vp.size(); ++i) {
		// 		cout << vp[i].first << " " << vp[i].second << "\n";
		// 	}
		// 	cout << "---------\n";
		// 	cout << vp[0].first << " " << vp[0].second << "\n";
		// }