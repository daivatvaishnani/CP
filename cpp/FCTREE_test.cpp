/**
* Problem Link: 
*/
#include <bits/stdc++.h>

using namespace std;

int MAXV = 1e6;
int MAXN = 1e5;
int MAXQ = 1e5;

void test_case() {
    cout << MAXN << "\n";
    for(int i = 0; i < MAXN; ++i) {
        int num = rand() % MAXV + 1;
        cout << num << " ";
    }
    cout << "\n";
    cout << MAXQ << "\n";
    for(int i = 0; i < MAXQ; ++i) {
        int a = rand() % MAXN + 1;
        int b = rand() % MAXN + 1;
        cout << a << " " << b << "\n";
    }
}

int main() {
    freopen("test", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cout << t << "\n";
    while(t--) {
        test_case();
    }
    return 0;
}