/**
* Problem Link: 
*/
#include <bits/stdc++.h>

using namespace std;

void print(string s, int k) {
    for(int i = 0; i < s.size(); ++i) {
        cout << s[i];
    }
    cout << "\n" << k << "\n";
}

void solve_fast(string s, int n) {
    string suf, pre, cs, small = s;
    int small_k = 1;
    for(int k = 1; k <= n; ++k) {
        suf = s.substr(0, k-1);
        pre = s.substr(k-1, n-k+1);
        if(((n & 1) && (k & 1)) || (!(n & 1) && !(k & 1))) {
            reverse(suf.begin(), suf.end());
        }
        cs = pre + suf;
        if(small > cs) {
            small = cs;
            small_k = k;
        }
    }
    print(small, small_k);
}

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        solve_fast(s, n);
    }   
    return 0;
}