/**
* Problem Link: https://www.codechef.com/APRIL20B/problems/UNITGCD
*/
#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 6;

int sieve[maxn];
vector<vector<int> > groups;

void construct_sieve(int n) {
    for(int i = 2; i <= n; i++) {
        if(sieve[i]) {
            continue;
        }
        int group_id = 0;
        for(int j = 2 * i; j <= n; j += i) {
            if(sieve[j]) {
                group_id = sieve[j];
            } else {
                group_id++;
                sieve[j] = group_id;
            }
        }
    }
}

void add_to_group(int group_id, int val) {
    while(groups.size() <= group_id) {
        groups.push_back({});
    }
    groups[group_id].push_back(val);
}

void test_case(int test) {
    int n;
    cin >> n;
    groups.clear();
    for(int i = 1; i <= n; ++i) {
        add_to_group(sieve[i], i);
    }
    cout << groups.size() << "\n";
    for(int i = 0; i < groups.size(); ++i) {
        cout << groups[i].size() << " ";
        for(int j = 0; j < groups[i].size(); ++j) {
            cout << groups[i][j];
            if(j < groups[i].size() - 1) {
                cout << " ";
            }
        }
        if(test == 0) {
            if(i < groups.size() - 1) {
                cout << "\n";
            }
        } else {
            cout << "\n";
        }
    }
}

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    construct_sieve(maxn - 1);
    while(t--) {
        test_case(t);
    }
    return 0;
}