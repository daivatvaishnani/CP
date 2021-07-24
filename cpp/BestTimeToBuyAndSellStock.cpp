/**
* Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
*/
#include <bits/stdc++.h>

using namespace std;

int maxProfit(vector<int>& a) {
    int n = a.size();
    if(n <= 1) {
        return 0;
    }
    int max_so_far = a[n-1], profit = 0;
    for(int i = n-1; i >= 0 ; --i) {
        profit = max(profit, max_so_far - a[i]);
        max_so_far = max(max_so_far, a[i]);
    }
    return profit;
}

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    return 0;
}