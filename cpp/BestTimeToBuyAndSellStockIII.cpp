/**
* Problem Link: 
*/
#include <bits/stdc++.h>

using namespace std;

int maxProfit(vector<int>& a) {
    int n = a.size();
    int max_profit = 0;
    if(n <= 1) return 0;
    vector<int> pr(n), pl(n);
    int min_so_far = a[0];
    for(int i = 0; i < n; ++i) {
        pl[i] = max(pl[i], a[i] - min_so_far);
        if(i > 0) pl[i] = max(pl[i-1], pl[i]);
        min_so_far = min(min_so_far, a[i]);
    }
    int max_so_far = a[n-1];
    for(int i = n-1; i >= 0; --i) {
        pr[i] = max(pr[i], max_so_far - a[i]);
        if(i < n-1) pr[i] = max(pr[i+1], pr[i]);
        max_so_far = max(max_so_far, a[i]);
    }
    for(int i = 1; i < n; ++i) {
        max_profit = max(max_profit, pl[i-1] + pr[i]);
    }
    max_profit = max(max_profit, pr[0]);
    return max_profit;
}

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    return 0;
}
