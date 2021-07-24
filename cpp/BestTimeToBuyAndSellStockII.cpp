/**
* Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
*/
#include <bits/stdc++.h>

using namespace std;

int maxProfit(vector<int>& a) {
    int n = a.size(), profit = 0;
    int last_bought_at = 0;
    if(n <= 1) {
        return 0;
    }
    for(int i = 1; i < n; ++i) {
        if(a[i] < a[i-1]) {
            profit += max(0, a[i-1] - a[last_bought_at]);
            last_bought_at = i;
        }
    }
    profit += max(0, a[n-1] - a[last_bought_at]);
    return profit;
}

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    return 0;
}