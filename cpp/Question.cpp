/**
* Problem Link: 
*/

/*

0 x x x 0
x 0 x 0 x
x x 0 x x
x 0 x 0 x
0 x x x 0

5x5
*/


#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if((i <= j && i <= n - j - 1) || (i >= j && i >= n - j - 1))    {
                cout << "o ";
            } else {
                cout << "x ";
            }
        }
        cout << "\n";
    }    
    return 0;
}