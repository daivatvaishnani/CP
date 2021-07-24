#include <bits/stdc++.h>

using namespace std;

#define si std::string::iterator

string match(string p, string c) {
	if(p.size() < c.size()) {
		swap(p, c);
	}
	int pi = p.size() - 1, ci = c.size() - 1;
	while(ci >= 0 && c[ci] == p[pi]) {
		--ci, --pi;
	}
	if(ci == -1) {
		return c;
	}
	else return "nil";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("in","r",stdin);
	freopen("out", "w", stdout);
	string p, c;
	cin >> p >> c;
	cout << match(p, c) << "\n"; 	
	return 0;
}