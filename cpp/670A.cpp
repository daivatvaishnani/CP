/**
* Problem Link: 
*/
#include <bits/stdc++.h>

using namespace std;

void test_case() {
	int n, no;
	cin >> n;
	vector<int> cnt(101, 0);
	for(int i = 0; i < n; ++i) {
		cin >> no;
		cnt[no]++;
	}
	int ans = 0;
	bool found2 = 0, found1 = 0;
	for(int i = 0; i < 101; ++i) {
		if(cnt[i] < 2) {
			ans += i;
			found2 = 1;
			break;
		}
	}
	if(!found2) {
		ans += 101;
	}
	for(int i = 0; i < 101; ++i) {
		if(cnt[i] < 1) {
			ans += i;
			found1 = 1;
			break;
		}
	}
	if(!found1) {
		ans += 101;
	}
	cout << ans << "\n";
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