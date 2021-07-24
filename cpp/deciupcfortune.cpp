#include <bits/stdc++.h>

using namespace std;

inline int i(char c) {
	return c - '0';
}

string f(string s) {
	string w = "";
	int szs = s.size();
	int carry = 0;
	int mul = 0;
	int digit = 0;
	int d = szs;
	while(d--) {
		mul = i(s[d]) * 11 + carry;
		digit = mul % 10;
		carry = mul / 10;
		w = w + to_string(digit);
	}
	reverse(w.begin(), w.end());
	if(carry != 0) {
		w = to_string(carry) + w;
	}
	return w;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("in","r",stdin);
	freopen("out", "w", stdout);
	int t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		cout << f(s) << "\n";
	}	
	return 0;
}