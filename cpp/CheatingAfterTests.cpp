#include <bits/stdc++.h>

using namespace std;

class CheatingAfterTests {
    public:
        int inc(int score) {
            int max_inc = INT_MIN;
            int u = score % 10;
            int t = score / 10;
            int maxu = t * 10 + 9, maxt = INT_MIN;
            if(t > 0) {
                maxt = 90 + u;
            } 
            max_inc = max(maxu, maxt) - score;
            return max_inc;
        }
        int cheat(vector<int> report) {
            int max_score = 0, max_inc = INT_MIN;
            for(int score : report) {
                max_score += score;
                max_inc = max(max_inc, inc(score));
            }
            return max_score + max_inc;
        }
};

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    vector<int> scores = {94, 6, 1, 4};
    CheatingAfterTests cheater;
    cout << cheater.cheat(scores) << "\n";
    return 0;
}