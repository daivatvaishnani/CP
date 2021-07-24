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
	// freopen("in","r",stdin);
	// freopen("out", "w", stdout);
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
		int ans = 0;
		int szo = one.size();
		int szt = two.size();
		if(szo >= 2 && szt >= 2) {
			for(int i = 0; i < szo; ++i) {
				mp[one[i]] = one[(i + 1) % szo];
			}
			for(int i = 0; i < szt; ++i) {
				mp[two[i]] = two[(i + 1) % szt];
			}
			for(int i = 1; i <= n; ++i) {
				b[i] = mp[a[i]];
			}
			for(int i = 1; i <= n; ++i) {
				if(a[i] != b[i]) {
					++ans;
				}
			}
			cout << ans << "\n";
			for(int i = 1; i <= n; ++i) {
				cout << b[i] << " ";
			}
		}
		else {
			if(szo == 0 && szt == 1) {
				cout << "0\n";
				cout << a[1] << " " << a[2];
			}
			else if(szo == 0 && szt > 1) {
				for(int i = 0; i < szt; ++i) {
					mp[two[i]] = two[(i + 1) % szt];
				}
				for(int i = 1; i <= n; ++i) {
					b[i] = mp[a[i]];
				}
				for(int i = 1; i <= n; ++i) {
					if(a[i] != b[i]) {
						++ans;
					}
				}
				cout << ans << "\n";
				for(int i = 1; i <= n; ++i) {
					cout << b[i] << " ";
				}
			}
			else if(szo == 1 && szt == 0) {
				cout << "0\n";
				cout << a[1];
			}
			else if(szo > 1 && szt == 0) {
				for(int i = 0; i < szo; ++i) {
					mp[one[i]] = one[(i + 1) % szo];
				}
				for(int i = 1; i <= n; ++i) {
					b[i] = mp[a[i]];
				}
				for(int i = 1; i <= n; ++i) {
					if(a[i] != b[i]) {
						++ans;
					}
				}
				cout << ans << "\n";
				for(int i = 1; i <= n; ++i) {
					cout << b[i] << " ";
				}	
			}
			else if(szo == 1 && szt == 1) {
				// 1 2 2
				mp[one[0]] = two[0];
				mp[two[0]] = one[0];
				single = two[0];
				for(int i = 1; i <= n; ++i) {
					if(single == a[i]) {
						b[i] = a[i];
						single = -1;
					}
					else {
						b[i] = mp[a[i]];
					}
				}
				for(int i = 1; i <= n; ++i) {
					if(a[i] != b[i]) {
						++ans;
					}
				}
				cout << ans << "\n";
				for(int i = 1; i <= n; ++i) {
					cout << b[i] << " ";
				}	
			}
			else if(szo > 1 && szt == 1) {
				for(int i = 0; i < szo; ++i) {
					mp[one[i]] = one[(i + 1) % szo];
				}
				p1 = mp[one[0]];
				p2 = mp[one[1]];
				mp[one[0]] = two[0];
				mp[one[1]] = two[0];
				paired = two[0];
				for(int i = 1; i <= n; ++i) {
					if(paired == a[i] && flag == 1) {
						b[i] = p1;
						flag = 0;
					}
					else if(paired == a[i] && flag == 0) {
						b[i] = p2;
						flag = 1;
						paired = -1;
					}
					else {
						b[i] = mp[a[i]];
					}
				}
				for(int i = 1; i <= n; ++i) {
					if(a[i] != b[i]) {
						++ans;
					}
				}
				cout << ans << "\n";
				for(int i = 1; i <= n; ++i) {
					cout << b[i] << " ";
				}
			}
			else if(szo == 1 && szt > 1) {
				for(int i = 0; i < szt; ++i) {
					mp[two[i]] = two[(i + 1) % szt];
				}
				p1 = one[0];
				mp[one[0]] = mp[two[0]];
				paired = two[0];
				for(int i = 1; i <= n; ++i) {
					if(paired == a[i] && flag == 1) {
						b[i] = p1;
						flag = 0;
					}
					else if(paired == a[i] && flag == 0) {
						b[i] = mp[a[i]];
						flag = 1;
						paired = -1;
					}
					else {
						b[i] = mp[a[i]];
					}
				}
				for(int i = 1; i <= n; ++i) {
					if(a[i] != b[i]) {
						++ans;
					}
				}
				cout << ans << "\n";
				for(int i = 1; i <= n; ++i) {
					cout << b[i] << " ";
				}
			}
		}
		cout << "\n";
	}
	return 0;
}


/*

*/