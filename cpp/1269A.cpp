#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    freopen("in", "r", stdin);
    ll n;
    cin >> n;
    if(n == 1) {
        cout << "9 8\n";
        return 0;
    }
    cout << 3*n << " " << 2*n << "\n";
    return 0;
}   