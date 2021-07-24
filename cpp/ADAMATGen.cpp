/**
* Problem Link: 
*/
#include <bits/stdc++.h>

using namespace std;

void test_case(int n) {
    vector<vector<int> > arr(n, vector<int> (n));
    for(int i = 0; i < n; ++i) {
    	for(int j = 0; j < n; ++j) {
    		arr[i][j] = i * n + j + 1;
    	}
    }
    unordered_set<int> transforms;
    for(int i = 0; i < n; ++i) {
    	int l = 1 + rand() % n;
    	if(l != 1) {
    		transforms.insert(l);	
    	}
    }
    for(int l : transforms) {
    	cout << l << " ";
    	for(int j = 0; j < l; ++j) {
    		for(int k = j; k < l; ++k) {
    			if(j != k) {
    				swap(arr[j][k], arr[k][j]);
    			}
    		}
    	}
    }
    cout << "\n";
    for(int i = 0; i < n; ++i) {
    	for(int j = 0; j < n; ++j) {
    		cout << arr[i][j] << "\t";
    	}
    	cout << "\n";
    }
    cout << "\n";
}

int main() {
    freopen("in_test", "r", stdin), freopen("out_test", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t, n;
    cin >> t >> n;
    while(t--) {
        test_case(n);
    }
    return 0;
}