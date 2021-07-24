#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> v;
vector<ll> ans;
long long t, n, k, value, first, last;
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    cin >> t;
    while(t--) {
        v.clear();
        ans.clear();
        cin >> n >> k;
        while(n--) {
            cin >> value;
            v.push_back(value);
        }
        n = v.size();
        for(int i=0; i<=k; ++i) {
            ans.push_back(v[i]*v[n-(k-i)-1]);
        }
        value = 0;
        for(int i=0; i<ans.size(); ++i)
            if(value < ans[i])  value = ans[i];
        cout << value << "\n"; 
    }
    return 0;
}
