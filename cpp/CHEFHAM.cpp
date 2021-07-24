#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;
int a[maxn], b[maxn], mp[maxn], f[maxn];
unordered_set<int> o, t;
vector<int> one, two;
int single = -1;
int paired = -1;
bool flag = 1;
int p1 = -1, p2 = -1;

inline void clr() {
	o.clear();
	t.clear();
	one.clear();
	two.clear();
	single = -1;
	paired = -1;
	p1 = -1;
	p2 = -1;
	flag = 1;
	for(int i = 0; i < maxn; ++i) {
		b[i] = -2;
		a[i] = -2;
		mp[i] = -2;
		f[i] = 0;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("in","r",stdin);
	freopen("out", "w", stdout);
	int tc;
	cin >> tc;
	while(tc--) {
		clr();
		int n;
		cin >> n;
		for(int i = 1; i <= n; ++i) {
			cin >> a[i];
			++f[a[i]];
		}
		for(int i = 1; i <= n; ++i) {
			if(f[a[i]] == 1) {
				if(o.find(a[i]) == o.end()) {
					o.insert(a[i]);
					one.push_back(a[i]);
				}
			}
			else if(f[a[i]] == 2) {
				if(t.find(a[i]) == t.end()) {
					t.insert(a[i]);
					two.push_back(a[i]);
				}
			}
		}
		int szo = one.size();
		int szt = two.size();
		if(szo & 1) {
			for(int i = 0; i < szo - 1; i += 2) {
				mp[one[i]] = one[i + 1];
				mp[one[i + 1]] = one[i];
			}
			if(szt & 1) {
				for(int i = 0; i < szt - 1; i += 2) {
					mp[two[i]] = two[i + 1];
					mp[two[i + 1]] = two[i];
				} 
				mp[one[szo - 1]] = two[szt - 1];
				mp[two[szt - 1]] = one[szo - 1];
				single = two[szt - 1];
			}
			else {
				for(int i = 0; i < szt; i += 2) {
					mp[two[i]] = two[i + 1];
					mp[two[i + 1]] = two[i];
				}
				mp[one[szo - 1]] = one[szo - 1]; 
			}
			if(szo == 1) {
				
			}
		}
		else {
			for(int i = 0; i < szo; i += 2) {
				mp[one[i]] = one[i + 1];
				mp[one[i + 1]] = one[i];
			}
			if(szt & 1) {
				for(int i = 0; i < szt - 1; i += 2) {
					mp[two[i]] = two[i + 1];
					mp[two[i + 1]] = two[i];
				}
				if(szo > 1) {
					mp[one[szo - 1]] = two[szt - 1];
					mp[one[szo - 2]] = two[szt - 1];
					paired = two[szt - 1];
					p1 = one[szo - 1];
					p2 = one[szo - 2];
				}
				else if(szo == 0) {
					mp[two[szt - 1]] = two[szt - 1];
				}
			}
			else {
				for(int i = 0; i < szt; i += 2) {
					mp[two[i]] = two[i + 1];
					mp[two[i + 1]] = two[i];
				}
			}
		}
		for(int i = 1; i <= n; ++i) {
			if(single == a[i]) {
				// cout << a[i] << " ";
				b[i] = a[i];
				single = -1;
			}
			else if(paired == a[i]) {
				if(flag == 1) {
					// cout << p1 << " ";
					b[i] = p1;
					flag = 0;
				}
				else {
					// cout << p2 << " ";
					b[i] = p2;
				}
			}
			else {
				// cout << mp[a[i]] << " ";
				b[i] = mp[a[i]];
			}
		}
		int ans = 0;
		for(int i = 1; i <= n; ++i) {
			if(a[i] != b[i]) {
				++ans;
			}
		}
		cout << ans << "\n";
		for(int i = 1; i <= n; ++i) {
			cout << b[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}


/*
1 2 3 4
2 1 8 8
6 7 8 6 7 8
7 6 3 7 5 4
*/