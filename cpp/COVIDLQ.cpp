/**
* Problem Link: https://www.codechef.com/APRIL20B/problems/COVIDLQ
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, no, ans = 1;
        cin >> n;
        vector<int> pos;
        for(int i = 0; i < n; ++i) {
            cin >> no;
            if(no == 1) {
                pos.push_back(i);
            }
        }
        if(pos.size() >= 2) {
            for(int i = 1; i < pos.size(); ++i) {
                if(pos[i] - pos[i-1] < 6) {
                    ans = 0;
                    break;
                }
            }
        }
        if(ans == 0) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
    return 0;
}