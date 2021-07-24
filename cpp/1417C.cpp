/**
* Problem Link: 
*/
#include <bits/stdc++.h>

using namespace std;

bool cmpr(const pair<int, int> &p1, const pair<int, int> &p2) {
	if(p1.second == p2.second) {
		return p1.first < p2.first;
	}
	return p1.second < p2.second;
}

void test_case() {
	int n;
	cin >> n;
	vector<int> a(n);
	unordered_map<int, int> lasta;
	unordered_map<int, int> maxg;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
		if(lasta.find(a[i]) == lasta.end()) {
			lasta.insert({a[i], i});
			maxg.insert({a[i], i});
		} else {		
			maxg[a[i]] = max(i - lasta[a[i]] - 1, maxg[a[i]]);
			lasta[a[i]] = i;
		}
	}
	for(auto i : maxg) {
		maxg[i.first] = max(n - lasta[i.first] - 1, maxg[i.first]);
	}
	// for(int i = 0; i < n; ++i) {
	// 	cout << a[i] << " ";
	// }
	// cout << "\n";
	vector<pair<int, int> > maxgarr;
	for(auto i : maxg) {
		maxgarr.push_back(i);
	}
	sort(maxgarr.begin(), maxgarr.end(), cmpr);
	// cout << "maxgrr\n";
	// for(auto i : maxgarr) {
	// 	cout << i.first << ": ";
	// 	cout << i.second << "\n";
	// }
	int curmaxg = -1, curmin = INT_MAX;
	vector<pair<int, int> > maxgarr_trns;
	for(int i = 0; i < maxgarr.size(); ++i) {
		if(curmaxg < maxgarr[i].second && curmin > maxgarr[i].first) {
			maxgarr_trns.push_back(maxgarr[i]);
			curmaxg = maxgarr[i].second;
			curmin = maxgarr[i].first;
		}
	}
	// cout << "maxgarr_trns\n";
	// for(auto i : maxgarr_trns) {
	// 	cout << i.first << ": ";
	// 	cout << i.second << "\n";
	// }
	vector<int> kamz(n, -1);
	for(int i = 0; i < maxgarr_trns.size(); ++i) {
		int l = maxgarr_trns[i].second;
		int r = n;
		if(i + 1 < maxgarr_trns.size()) {
			r = maxgarr_trns[i+1].second;
		}
		for(int j = l; j < r; ++j) {
			kamz[j] = maxgarr_trns[i].first;
		}
	}
	// cout << "kamz\n";
	for(int i = 0; i < n; ++i) {
		cout << kamz[i] << " ";
	}
	cout << "\n";
	// cout << "------------------\n";
}

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        test_case();
    }
    return 0;
}