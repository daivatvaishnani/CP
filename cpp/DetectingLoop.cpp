/**
* Problem Link: 
*/
#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x) {}
};

bool isLoopPresent(Node *start) {
    bool ans = 0;
    Node *slow = start;
    Node *fast = start;
    while(!slow->next && !fast->next && !fast->next->next) {
        if(slow != fast) {
            slow = slow->next;
            fast = fast->next->next;
        } else {
            ans = 1;
            break;
        }
    }
    return ans;
}

/*      0 1 2 3 4 5 6 7 8 9 10 11 12
    x = 1 1 2 3 4 7 7 7 7 5 8 9 9
    bool first = 0, last = 0;
    int start = -1, end = -1;               x x x x x * * * 7 - - - 7 
    for(int i : x) {
        if(i == 7 && !first) {
            first = 1;
            start = id;
        } else {
            if(i > 7 && !last) {
                last = 1;
                end = i;
                break;
            }
        }
    }
    if(first && last) {
        
    }

    find_first() {
        left = 0, right = sizeof(x);
        while(left < right - 1) {
            mid = (left + right)/2;
            if(x[mid] >= 7) {
                // look left subarr
                right = mid - 1;
            } else if(mid < 7) {
                // look in right subarr
                left = mid + 1;
            }
        }
        // left = right - 1, right
        // we have to check now, 
        // return smaller index of both which ever is 7
    }

    find_last() {
        left = 0, right = sizeof(x);
        while(left < right - 1) {
            mid = (left + right)/2;
            if(x[mid] < 7) {
                // look left subarr
                right = mid - 1;
            } else if(mid >= 7) {
                // look in right subarr
                left = mid + 1;
            }
        }
    }


    int left = 0, right = n;
    int mid = (left + right) / 2;

    

*/

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    return 0;
}