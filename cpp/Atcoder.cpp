#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, mn = INT_MAX, no, cnt = 0;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> no;
        mn = min(no, mn);
        if(mn >= no) {
            cnt++;
        }
    }
    cout << cnt << "\n";
    return 0;
}