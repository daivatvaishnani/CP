/**
* Problem Link: 
*/
#include <bits/stdc++.h>

using namespace std;

void test_case() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    int lowi = 0;
    for(int i = 0; i < n; ++i) {
    	cin >> a[i];
    	if(a[i] < a[lowi]) {
    		lowi = i;
    	}
    }
    int ans = 0;
    for(int i = 0; i < n; ++i) {
    	if(i != lowi) {
    		int diff = abs(k - a[i]);
    		ans += diff / a[lowi];
    	}
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