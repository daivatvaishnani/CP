#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 5;
unordered_set<int> s;
int stamp[maxn];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	// freopen("in","r",stdin);
	// freopen("out", "w", stdout);
	int n;
	int val;
	cin >> n;
	s.clear();
	for(int i = 0; i < n; ++i) {
		cin >> val;
		if(s.find(val) == s.end()) {
			s.insert(val);
		}
		stamp[val] = i;
	}
	int mini = *s.begin();
	for(int i : s) {
		if(stamp[i] < stamp[mini]) {
			mini = i;
		}
	}
	cout << mini << "\n";
	return 0;
}