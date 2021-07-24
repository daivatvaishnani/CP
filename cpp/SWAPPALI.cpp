#include <bits/stdc++.h>

using namespace std;

const int TH = 26;

bool is_pal(string s) {
    string rev_s = s;
    reverse(rev_s.begin(), rev_s.end());
    return s == rev_s;
}

void print(bool ans, int nops = INT_MAX) {
    cout << (ans ? "YES" : "NO") << "\n";
    if(ans) {
        cout << nops << "\n";
    }
}

void solve(string s, int n) {
    vector<int> f(TH, 0);
    n = s.length();
    for(int i = 0; i < n; ++i) {
        f[s[i]-'a']++;
    }
    bool has_it_all = 1;
    int odd_cnt_nums = -1; 
    for(int i = 0; i < TH; ++i) {
        if(f[i] & 1) {
            if(odd_cnt_nums == -1) {
                odd_cnt_nums = i;
            } else {
                has_it_all = 0;
            }
        }
    }
    if(!has_it_all) {
        print(0);
    }
    int l = 0, r = n-1;
    vector<bool> moved(n, 0);
    int swaps = 0;
    while(l < r) {
        // cout << s.substr(l, r-l+1) << "\n";
        // cout << s[l] << " " << s[r] << "\n";
        if(s[l] != s[r]) {
            if(moved[l] || moved[r]) {
                if(moved[l] && moved[r]) {
                    print(0);
                    return;
                }
                if(moved[l]) {
                    // find replacement on r side
                    bool found = 0;
                    for(int i = l+1; i < r; ++i) {
                        if(s[i] == s[l]) {
                            found = 1;
                            swap(s[i], s[r]);
                            moved[i] = true;
                            moved[r] = true;   
                        }
                    }
                    if(!found) {
                        print(0);
                        return;
                    }
                } else {
                    // find replacement on l side
                    bool found = 0;
                    for(int i = l+1; i < r; ++i) {
                        if(s[i] == s[r]) {
                            found = 1;
                            swap(s[i], s[l]);
                            moved[i] = true;
                            moved[l] = true;
                        }
                    }
                    if(!found) {
                        print(0);
                        return;
                    }
                }
            } else {
                // find replacement on r side
                bool found = 0;
                for(int i = l+1; i < r; ++i) {
                    if(s[i] == s[l]) {
                        found = 1;
                        swap(s[i], s[r]);
                        moved[i] = true;
                        moved[r] = true;
                    }
                }
                if(!found) {
                    // find replacement on l side
                    for(int i = l+1; i < r; ++i) {
                        if(s[i] == s[r]) {
                            found = 1;
                            swap(s[i], s[l]);
                            moved[i] = true;
                            moved[l] = true;
                        }
                    }
                }
                if(!found) {
                    print(0);
                    return;
                }
            }
            swaps++;
        }
        l++;
        r--;
    }
    // cout << s << "\n";
    if(!is_pal(s)) {
        print(0);
        return;
    }
    print(1, swaps);
}

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        string s;
        cin >> n >> s;
        solve(s, n);
        // solve_task(s, n);
    }
    return 0;
}