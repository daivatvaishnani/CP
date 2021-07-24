#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void insert(ll i, vector<vector<ll> > &pos, vector<ll> &dis, ll x) {
	pos[i].push_back(x);
	if(pos[i].size() == 2) {
		dis[i] = pos[i][1]-pos[i][0];
	} else if(pos[i].size() > 2) {
		dis[i] = min(dis[i], pos[i][2]-pos[i][1]);
		pos[i][0] = pos[i][1];
		pos[i][1] = pos[i][2];
		pos[i].pop_back();
		return;
	}
}

ll solve(ll n, string &s) {
	/*
		1. A = B (A & B are substrings of s of lenght K)
		2. A and B can use same indices at most K - 1 times.

		i.e. A and B have to use at least one different index
		a1 a2 a3 a4 ... ak
		b1 b2 b3 b4 ... bk 
	*/
	ll ans = 0, mind = LLONG_MAX;
	vector<vector<ll> > pos(26);
	vector<ll> dis(26, LLONG_MAX);
	for(ll i = 0; i < s.length(); ++i) {
		insert(s[i]-'a', pos, dis, i);
	}
	// for(ll c = 0; c < 26; ++c) {
	// 	cout << (char)(c+'a') << " : ";
	// 	for(ll i : pos[c]) {
	// 		cout << i << " ";
	// 	}
	// 	cout << "\n";
	// }
	for(ll c = 0; c < 26; ++c) {
		if(pos[c].size() == 2) {
			mind = min(mind, dis[c]);
		}
	}
	if(mind != LLONG_MAX) {
		ans = s.length() - mind;
	}
	return ans;
}

int main() {
	freopen("in", "r", stdin), freopen("out", "w", stdout);
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll t;
	cin >> t;
	while(t--) {
		ll n;
		string s;
		cin >> n >> s;
		cout << solve(n, s) << "\n";
	}
	return 0;
}
