#include <bits/stdc++.h>

using namespace std;

class BinaryHeapLeaf {
    public:
        vector<int> maxDiff(int N) {
            int no_of_leafs = N/2 + 1;
            vector<int> ans;
            if(N <= 3) {
                ans.push_back(no_of_leafs);
                ans.push_back(no_of_leafs);
            } else {
                ans.push_back(no_of_leafs);
                // find max possible number that can be in the leaf
                ans.push_back(N - floor(log2(N)) + 1);
            }
            return ans;
        }
};

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    BinaryHeapLeaf heap;
    vector<int> ans = heap.maxDiff(47);
    cout << ans[0] << " " << ans[1] << "\n";
    return 0;
}