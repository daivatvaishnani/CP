#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    long long n, a, b, c, t, x, x1, x2, x3;
    cin >> t;
    while(t--) {
        cin >> a >> b >> c >> n;
        if((n + a + b + c) % 3 == 0) {
            x = (n + a + b + c)/3;
            x1 = x - a;
            x2 = x - b;
            x3 = x - c;
            if(x1 >= 0 && x2 >= 0 && x3 >= 0) {
                cout << "YES\n";
                continue;
            }
        }
        cout << "NO\n";
    }
    return 0;
}