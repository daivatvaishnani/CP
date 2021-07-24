#include <bits/stdc++.h>

using namespace std;

unordered_set<int> blocked[3];
int blockers = 0;

bool isBlocked(int r, int c) {
    return blocked[r].find(c) != blocked[r].end();
}

void block(int r, int c) {
    int other = r == 1 ? 2 : 1;
    if(isBlocked(other, c)) blockers++;
    if(isBlocked(other, c+1)) blockers++;
    if(isBlocked(other, c-1)) blockers++;
    blocked[r].insert(c);
}

void unblock(int r, int c) {
    int other = r == 1 ? 2 : 1;
    if(isBlocked(other, c)) blockers--;
    if(isBlocked(other, c+1)) blockers--;
    if(isBlocked(other, c-1)) blockers--;
    blocked[r].erase(blocked[r].find(c));
}

void toggle(int r, int c) {
    if(isBlocked(r, c)) {
        unblock(r, c);
        return;
    }
    block(r, c);
}

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, q, r, c;
    cin >> n >> q;
    for(int i = 0; i < q; ++i) {
        cin >> r >> c;
        toggle(r, c);
        if(blockers > 0) {
            cout << "No\n";
        } else {
            cout << "Yes\n";
        }
    }
    return 0;
}