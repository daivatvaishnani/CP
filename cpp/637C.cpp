/**
* Problem Link: 
*/
#include <bits/stdc++.h>

using namespace std;

void test_case(int case_no) {
    int n;
    cin >> n;
    vector<int> pos(n+1), val(n+1);
    for(int i = 0; i < n; ++i) {
        cin >> val[i+1];
        pos[val[i+1]] = i+1;
    }
    // cout << "pos:\n";
    // for(int i = 0; i < n; ++i) {
    //     cout << i+1 << " " << pos[i+1] << "\n";
    // }
    int i = 1, rem = n, con = 0;
    while(i <= n) {
        if(con) {
            if(pos[i] == pos[i-1]+1) {
                i++;
                rem--;
            } else {
                if(pos[i-1] == n || val[pos[i-1] + 1] < i-1) {
                    con = 0;
                } else {
                    cout << "No\n";
                    return;
                }
            }
        } else {
            if(pos[i] == rem) {
                i++;
                rem--;
            } else {
                con = 1;
                i++;
                rem--;
            }
        }
        
    }
    cout << "Yes\n";
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