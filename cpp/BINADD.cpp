#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define dbg(x) cout << #x << ": " << x << ", "
#define nl cout << "\n";

bool is_greater_than_zero(const string &s) {
	for(int i = 0; i < s.length(); ++i) {
		if(s[i] == '1') {
			return true;
		}
	}
	return false;
}

string _xor_(const string &a, const string &b) {
	string a_xor_b = "";
	for(int i = 0; i < a.length(); ++i) {
		a_xor_b += (a[i] == b[i]) ? '0' : '1';	
	}
	return a_xor_b;
}

string _and_(const string &a, const string &b) {
	string a_and_b = "";
	for(int i = 0; i < a.length(); ++i) {
		a_and_b += (a[i] == '1' && b[i] == '1') ? '1' : '0';	
	}
	return a_and_b;
}

string left_shift(const string &s) {
	int ls = s.length();
	string left;
	if(s[0] == '0') {
		left = s.substr(1, ls-1);	
	} else {
		left = s;
	}
	left += '0';
	return left;
}

ll binary_to_ll(const string &s) {
	ll ans = 0;
	ll ls = s.length();	
	for(int i = 0; i < ls; ++i) {
		if(s[i] == '1') {
			ans += 1 << (ls-i-1);
		}
	}
	return ans;
}

void pre_process(string &a, string &b) {
	int la = a.length();
	int lb = b.length();
	if(la > lb) {
		b = string(la-lb, '0') + b;
	} else {
		a = string(lb-la, '0') + a;
	}
}

ll solve_slow(string a, string b) {
	ll count = 0;
	string u, v;
	while(is_greater_than_zero(b)) {
		pre_process(a, b);
		u = _xor_(a, b);
		v = _and_(a, b);
		a = u;
		b = left_shift(v);
		count++;
	}
	return count;
}

ll solve_slowest(const string &a, const string &b) {
	ll count = 0;
	ll A = binary_to_ll(a), B = binary_to_ll(b), U = -1, V = -1;
	// dbg(A), dbg(B), dbg(U), dbg(V), nl; 
	while(B > 0) {
		U = A ^ B;
		V = A & B;
		A = U;
		B = V * 2;
		// dbg(A), dbg(B), dbg(U), dbg(V), nl; 
		count++;
	}
	return count;
}

int main() {
	freopen("in", "r", stdin), freopen("out", "w", stdout);
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while(t--) {
		string a, b;
		cin >> a >> b;
		pre_process(a, b);
		// cout << solve_slowest(a, b) << "\n";
		cout << solve_slow(a, b) << "\n";
	}
	return 0;
}
