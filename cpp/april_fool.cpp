/**
* Problem Link: 
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    vector<int> a = {1, 4, 4, 0, 4, 5};
    int end = a[0];
    for(int i = 1; i < a.size(); ++i) {
        end &= a[i];
    }
    cout << end << "\n";
    return 0;
}