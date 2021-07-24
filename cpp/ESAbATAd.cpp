/**
* Problem Link: 
*/
#include <bits/stdc++.h>

using namespace std;

int query(int i) {
    cout << i << endl;
    int value;
    cin >> value;
    return value;
}

string print_ans(vector<int> &a) {
    string ans = "";
    for(int i = 0; i < a.size(); ++i) {
        ans += (a[i] + '0');
    }
    cout << ans << endl;
}

void solve(int i, int b) {
    vector<int> a(b);
    for(int i = 0; i < b; ++i) {
        a[i] = query(i);
    }
    string verdict = print_ans(a);
    assert(verdict == "Y");
}

int main() {
    // freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t, b;
    cin >> t >> b;
    for(int i = 1; i <= t; ++i) {
        solve(i, b);
    }
    return 0;
}

