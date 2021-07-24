#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> Date;

#define actual first
#define early second

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<Date> dates(n);
    for(int i = 0; i < n; ++i) {
        cin >> dates[i].actual >> dates[i].early;
    }
    sort(dates.begin(), dates.end());
    int curr_date = -1, date_selected;
    for (int i = 0; i < n; ++i) {
        date_selected = dates[i].early >= curr_date ? dates[i].early : dates[i].actual;
        curr_date = date_selected;
    }
    cout << curr_date << "\n";
    return 0;
}