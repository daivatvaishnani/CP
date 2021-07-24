/**
* Problem Link: https://www.codechef.com/APRIL20B/problems/ANSLEAK
*/
#include <bits/stdc++.h>

using namespace std;

int choose_answer(vector<int> &corrects) {
    vector<int> frequency(10);
    for(int i : corrects) {
        frequency[i]++;
    }
    int max_frequency = 1;
    for(int i = 2; i <= 9; ++i) {
        if(frequency[i] > frequency[max_frequency]) {
            max_frequency = i;
        } else if(frequency[i] == frequency[max_frequency]) {
            int chance = rand() % 2;
            if(chance == 1) {
                max_frequency = i;
            }
        }
    }
    return max_frequency;
}

void test_case() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int> > corrects(n, vector<int> (k, 0)); 
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < k; ++j) {
            cin >> corrects[i][j];
        }
    }
    int answer;
    for(int i = 0; i < n; ++i) {
        answer = choose_answer(corrects[i]);
        cout << answer << " ";
    }
    cout << "\n";
}

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        test_case();
    }
    return 0;
}