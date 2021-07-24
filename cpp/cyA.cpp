#include <bits/stdc++.h>

using namespace std;

const int maxp = 19;
long long POW[maxp];

inline void fill() { POW[0] = 1; for(int i = 1; i <= 18; ++i) { POW[i] = POW[i - 1]*10; } }
inline int dc(char c) { return (c - '0'); }
inline int n
inline int gmbc(char bc) {
	return nc(bc) - 9;
}

int toi(string s) {
	int i = 0, res = 0;
	while(s[i] == '0') ++i;
	for(int j = i; j < s.size(); ++i) {
		res += 1LL* dc[s[i]] * POW[s.size() - i - 1];
	}
}

string cb(string s, int b) {
	long long no = toi(s);
	string rs = "";
	while(no > 0) {
		no = no / 3;
		rs = ((no % 3) + '0') + rs;
	}
	cout << rs << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("in","r",stdin);
	freopen("out", "w", stdout);
	string n, q, p;
	cin >> n >> q >> p;	
	cout << cb("27", 3) << "\n";
	return 0;
}