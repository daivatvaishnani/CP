/**
* Problem Link: 
*/
#include <bits/stdc++.h>

using namespace std;

vector<int> btfy(vector<int> &a) {
    vector<int> b;
    return b;
}

void test_case(int case_no) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> b = btfy(a);
    if(b.size() == 0) {
        cout << "-1\n";
    } else {
        cout << b.size() << "\n";
        for(int i : b) {
            cout << i << " ";
        }
        cout << "\n";
    }
}

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    for(int i = 1; i <= t; ++i) {
        test_case(i);
    }
    return 0;
}