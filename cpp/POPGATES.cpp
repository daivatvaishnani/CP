#include <bits/stdc++.h>

using namespace std;

#define heads 1
#define tails 0

void flip(vector<int> &a, int l, int r) {
    for(int i = l; i <= r; ++i) {
        a[i] = (a[i] + 1) & 1;
    }
}

void print(vector<int> &a) {
    for(int i = 0; i < a.size(); ++i) {
        cout << a[i] << " ";
    }
    cout << "\n";
}

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        char c;
        cin >> n >> k;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) {
            cin >> c;
            if(c == 'H') {
                a[i] = heads;
            } else {
                a[i] = tails;
            }
        }
        reverse(a.begin(), a.end());
        for(int i = 0; i < k; ++i) {
            if(a[i] == heads) {
                flip(a, i+1, n-1);
            }
            a[i] = -1;
        }
        int count = 0;
        for(int i = 0; i < n; ++i) {
            count += (a[i] == 1);
        }
        cout << count << "\n";
    }
    return 0;
}