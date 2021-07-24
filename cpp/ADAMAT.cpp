/**
* Problem Link: https://www.codechef.com/SEPT20A/problems/ADAMAT
*/
#include <bits/stdc++.h>

using namespace std;

void test_case() {
    int n;
    cin >> n;
    vector<vector<int> > arr(n, vector<int> (n));
    for(int i = 0; i < n; ++i) {
    	for(int j = 0; j < n; ++j) {
    		cin >> arr[i][j];
    	}
    }
    for(int i = 0; i < n; ++i) {
    	for(int j = 0; j < n; ++j) {
    		cout << arr[i][j] << " ";
    	}
    	cout << "\n";
    }
    cout << "\n";
    for(int i = 0; i < n; ++i) {
    	for(int j = 0; j < n; ++j) {
    		cout << i * n + j + 1 << " ";
    	}
    	cout << "\n";
    }
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