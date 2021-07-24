#include <bits/stdc++.h>

using namespace std;

string solve(int zeros, int ones) {
    string ans = "";
    if(zeros > ones + 1 || ones > 2*(zeros + 1)) {
        return "-1";
    }
    if(zeros >= ones) {
        for(int i = 0; i < ones; ++i) {
            ans += "01";
        }
        if(zeros > ones) {
            ans += "0";
        }
        return ans;
    } 
    int twos = ones - zeros - 1;
    for(int i = 0; i < zeros; ++i) {
        ans += twos > 0 ? "110" : "10";
        twos--;
    }
    ans += twos > 0 ? "11" : "1";
    return ans;
}

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int zeros, ones;
    cin >> zeros >> ones;
    cout << solve(zeros, ones) << "\n";
    return 0;
}
