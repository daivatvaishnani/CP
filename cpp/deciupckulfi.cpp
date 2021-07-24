#include <bits/stdc++.h>

using namespace std;

#define ci first
#define di second 

vector< pair<int, int> > v;

bool cmp(pair<int, int> p1, pair<int, int> p2) {
	return p1.di/p1.ci > p2.di/p2.ci;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("in","r",stdin);
	freopen("out", "w", stdout);
	int t;
	cin >> t;
	while(t--) {
		int n, d;
		cin >> n >> d;
		v.clear();
		while(n--) {
			string name;
			int del, cost;
			cin >> name >> del >> cost;
			v.push_back({cost, del});
		}
		sort(v.begin(), v.end());
		int needed = d;
		int got = 0;
		int money = 0;
		for(int i = 0; i < v.size(); ++i) {

		}
		cout << money << " " << got << "\n";
	}	
	return 0;
}