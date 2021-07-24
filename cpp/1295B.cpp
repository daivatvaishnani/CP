#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    for(int i = 0; i < t; ++i) {
        int len, bal;
        string sub;
        cin >> len >> bal >> sub;
        // cout << len << " " << bal << " " << sub << "\n";
        vector<int> bal_sub(len);
        bal_sub[0] = (sub[0] == '0') ? 1 : -1;
        for(int i = 1; i < len; ++i) {
            bal_sub[i] += bal_sub[i-1];
            bal_sub[i] += (sub[i] == '0') ? 1 : -1;
        }
        // for(int i = 0; i < len; ++i) {
        //     cout << bal_sub[i] << "\n";
        // }
        // cout << "----\n";
        int tot = (bal == 0) ? 1 : 0;
        for(int i = 0; i < len; ++i) {
            if(bal_sub[len - 1] == 0) {
                if(bal - bal_sub[i] == 0) {
                    tot = -1;
                    break;
                }
            } else if((bal - bal_sub[i]) % bal_sub[len - 1] == 0) {
                tot += ((bal - bal_sub[i]) / bal_sub[len - 1]) >= 0 ? 1 : 0;
            }
        }
        cout << tot << "\n";
        // cout << "----\n";
    }
    return 0;
}