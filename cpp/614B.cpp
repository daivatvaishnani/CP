#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    double n, ans;
    scanf("%lf", &n);
    vector<double> f((int)n+1, -1);
    f[1] = 1;
    for(double j = 2; j <= n; ++j) {
        f[(int)j] = 1/j + f[(int)j-1];
    }
    // for(double j = 1; j <= n; ++j) {
    //     cout << f[(int)j] << " ";
    // }
    // cout << "\n";
    printf("%0.10lf", f[(int)n]);
    return 0;
}