/**
* Problem Link: 
*/              
#include <bits/stdc++.h>

using namespace std;

void test_case(int case_no) {
    double r;
    cin >> r;
    cout << std::setprecision(20);
    cout << 2 * acos(-1) * r << "\n";    
}

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    for(int i = 1; i <= t; ++i) {
        test_case(i);
    }
    return 0;
}