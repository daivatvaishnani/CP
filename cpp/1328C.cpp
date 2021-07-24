/**
* Problem Link: 
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string num, a, b;
        cin >> num;
        a = "1", b = "1";
        bool done = 0;
        for(int i = 1; i < n; ++i) {
            int c = num[i]-'0';
            if(c == 0) {
                a += "0", b += "0";
            } else if(c == 1) {
                if(!done) {
                    a += "1", b += "0";
                    done = 1;
                } else {
                    a += "0", b += "1";
                }
            } else {
                if(!done) {
                    a += "1", b += "1";
                } else {
                    a += "0", b += "2";
                }
            }
        }
        cout << a << "\n";
        cout << b << "\n";
    }
    return 0;
}