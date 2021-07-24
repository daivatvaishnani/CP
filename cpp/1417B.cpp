/**
* Problem Link: 
*/
#include <bits/stdc++.h>

using namespace std;

void test_case() {
	int n, T;
	cin >> n >> T;
	vector<pair<int, int> > a(n);
	vector<int> p(n, 1);
	for(int i = 0; i < n; ++i) {
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a.begin(), a.end());
	// for(auto i : a) {
	// 	cout << i.first << " " << i.second << "\n";
	// }
	// cout << "\n";
	if(n == 1) {
		cout << "0\n";
		return;
	}
	if(n == 2) {
		cout << "0 1\n";
		return;
	}
	int id = 0;
	while(id+1 < n && a[id].first + a[id+1].first < T) {
		id++;
	}
	// cout << id << "\n";
	for(int i = 0; i <= id; ++i) {
		p[a[i].second] = 0;
	}
	for(int i = 0; i < n; ++i) {
		cout << p[i] << " ";
	}
	cout << "\n";
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