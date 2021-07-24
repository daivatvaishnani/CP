/**
* Problem Link: 
*/
#include <bits/stdc++.h>

using namespace std;

class ChessBoard {
    vector<vector<int>> board;
    int size = 8;

    string getCellName(int i, int j) {
        return  char('a' + j) + to_string(i+1);
    }

    void placeChessPieces() {
        for(int i = 0; i < size; ++i) {
            for(int j = 0; j < size; ++j) {
                cout << getCellName(i, j) << "\n";
            }
        } 
    }
public:
    ChessBoard(int n = 8) {
        size = n;
        board.resize(size);
        for(int i = 0; i < size; ++i) {
            board[i].resize(size);
        }
        placeChessPieces();
    }
};

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ChessBoard board;
    return 0;
}
