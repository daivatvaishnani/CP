#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, nm;
        string s;
        cin >> n;
        cin >> s;
        vector<int> o;
        for(int i = 0; i < n; ++i) {
            nm = s[i]-'0';
            if(nm % 2 == 1) {
                o.push_back(nm);
                if(o.size() == 2) {
                    break;
                }
            }
        }
        if(o.size() >= 2)  {
            cout << o[0] << o[1] << "\n";
        } else {
            cout << "-1\n";
        }
    }
    return 0;
}