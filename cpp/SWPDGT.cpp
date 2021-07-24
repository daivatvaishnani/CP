/**
* Problem Link: https://www.codechef.com/LTIME82B/problems/SWPDGT
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t, a, b;
    cin >> t;
    while(t--) {
        cin >> a >> b;
        int a2 = a % 10, a1 = a / 10;
        int b2 = b % 10, b1 = b / 10;
        vector<int> ans;
        int ans1 = ((a1 + b1)*10 + a2 + b2);
        int ans2 = (b1 != 0) ? ((a1 + a2)*10 + b1 + b2) : INT_MIN;
        int ans3 = (a1 != 0) ? ((b1 + b2)*10 + a1 + a2) : INT_MIN;
        cout << max(ans1, max(ans2, ans3)) << "\n";
    }
    return 0;
}