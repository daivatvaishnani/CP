/**
* Problem Link: 
*/
#include <bits/stdc++.h>

using namespace std;

const int MX_ITRS = 1e6;

struct Qnode {
    int x, y, depth;
    string path;
    Qnode() {

    }
    Qnode(int x, int y, int depth, string path) {
        this->x = x;
        this->y = y;
        this->depth = depth;
        this->path = path;
    }
};

queue<Qnode> q;

void clearQueue() {
    while(!q.empty()) {
        q.pop();
    }
}

void test_case(int case_no) {
    // int x, y;
    // cin >> x >> y;
    // Qnode top;
    // q.push(Qnode(0, 0, 0, ""));
    // string minPath;
    // if((x & 1) && (y & 1)) {
    //     minPath = "IMPOSSIBLE";
    // } else {
    //     while(!q.empty()) {
    //         top = q.front();
    //         int cx = top.x;
    //         int cy = top.y;
    //         int depth = top.depth; 
    //         string path = top.path;
    //         q.pop();
    //         if(cx == x && cy == y) {
    //             minPath = path;
    //             break;
    //         }
    //         int stepsize = (1<<depth);
    //         q.push(Qnode(cx+stepsize, cy, depth+1, path+'E'));
    //         q.push(Qnode(cx-stepsize, cy, depth+1, path+'W'));
    //         q.push(Qnode(cx, cy+stepsize, depth+1, path+'N'));
    //         q.push(Qnode(cx, cy-stepsize, depth+1, path+'S'));
    //     }
    // }    
    // cout << "Case #" << case_no << ": " << minPath << "\n";
}

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    for(int i = 1; i <= t; ++i) {
        clearQueue();
        int x, y;
        cin >> x >> y;
        Qnode top;
        q.push(Qnode(0, 0, 0, ""));
        string minPath;
        if((x & 1) && (y & 1)) {
            minPath = "IMPOSSIBLE";
        } else {
            while(!q.empty()) {
                top = q.front();
                int cx = top.x;
                int cy = top.y;
                int depth = top.depth; 
                string path = top.path;
                q.pop();
                if(cx == x && cy == y) {
                    minPath = path;
                    break;
                }
                int stepsize = (1<<depth);
                q.push(Qnode(cx+stepsize, cy, depth+1, path+'E'));
                q.push(Qnode(cx-stepsize, cy, depth+1, path+'W'));
                q.push(Qnode(cx, cy+stepsize, depth+1, path+'N'));
                q.push(Qnode(cx, cy-stepsize, depth+1, path+'S'));
            }
        }    
        cout << "Case #" << i << ": " << minPath << "\n";
    }
    return 0;
}