#include <bits/stdc++.h>

using namespace std;

#define batch first
#define targeted second

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int> > a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i].batch;
    }
    for(int i = 0; i < n; ++i) {
        cin >> a[i].targeted;
    }
    sort(a.begin(), a.end());
    for(auto &p : a) {
        cout << p.batch << " " << p.targeted << "\n";
    }
    vector<int> bat, tar;    
    pair<int, int> last = {0, INT_MIN};
    for(int i = 0; i < n; ++i) {
        if(a[i].batch == last.batch) {
            last.batch = a[i].batch;
            if(a[i].targeted > last.targeted) {
                last.targeted = a[i].targeted;
            }
        } else {
            if(last.batch != 0) {
                bat.push_back(last.batch);
                tar.push_back(last.targeted);
            }
            last = a[i];
        }
    }
    bat.push_back(last.batch);
    tar.push_back(last.targeted);
    cout << "------\n";
    for(int i = 0; i < tar.size(); ++i) {
        cout << bat[i] << " " << tar[i] << "\n";
    }
    for(int i = 0; i < n; ++i) {
        int id = (upper_bound(bat.begin(), bat.end(), a[i].batch) - bat.begin());
        cout << a[i].batch << " " << id << "--\n"; 
    }
    return 0;
}