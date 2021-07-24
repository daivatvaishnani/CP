#include <bits/stdc++.h>

using namespace std;

vector<bool> moves; // 0 STRIKE, 1 HEAL

int main() {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    int vh, va, vhp, mh, ma;
    bool turn = 0;
    cin >> vh >> va >> vhp >> mh >> ma;
    moves.clear(); 
    while(mh > 0) {
        if(!turn) {
            if(va >= mh) {
                // strike
                mh -= va;
                moves.push_back(0);
            }
            else {
                if(vh <= ma) {
                    // heal
                    vh += vhp;
                    moves.push_back(1);
                }
                else {
                    if(vh - ma > mh - va || ) {
                        // strike
                        mh -= va;
                        moves.push_back(0);           
                    }
                    else {
                        // heal
                        vh += vhp;
                        moves.push_back(1);    
                    }
                }
            }
        }
        else vh -= ma;
        turn = !turn;
    }
    cout << moves.size() << "\n";
    for(int i = 0; i < moves.size(); ++i) {
        if(!moves[i]) cout << "STRIKE\n";
        else cout << "HEAL\n";
    }
    return 0;   
}