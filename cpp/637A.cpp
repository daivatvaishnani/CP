/**
* Problem Link: 
*/
#include <bits/stdc++.h>

using namespace std;

bool between(int a, int b, int c) {
    return c >= a && c <= b;
}

void test_case(int case_no) {
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    int minw = n*(a-b), maxw = n*(a+b);
    int minn = c-d, maxn = c+d;
    if(between(minn, maxn, minw) || between(minn, maxn, maxw) 
        || between(minw, maxw, minn) || between(minw, maxw, maxn)) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    for(int i = 1; i <= t; ++i) {
        test_case(i);
    }
    return 0;
}