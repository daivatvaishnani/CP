/**
* Problem Link: 
*/
#include <bits/stdc++.h>

using namespace std;

void test_case(int case_no) {
    int last = 1;
    int gapSize = 5;
    for(int i = 0; i < 4; ++i) {
        last = last + rand() % gapSize;
        cout << last << " ";
    }
    cout << "\n";
}

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1e5;
    cout << t << "\n";
    for(int i = 1; i <= t; ++i) {
        test_case(i);
    }
    return 0;
}