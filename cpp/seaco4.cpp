#include <bits/stdc++.h>

using namespace std;

const long long N = 1e5;
const long long M = 1e9+7;

long long a[N];    
pair<long long, pair<long, long> > q[N];

#define tt first
#define ll second.first
#define rr second.second

void updateBIT(long long BITree[], int n, int index, long long val) {
    index = index + 1;
    while (index <= n) {
        BITree[index] += val;
        index += index & (-index);
    }
}

long long *constructBITree(long long arr[], int n) {
    long long *BITree = new long long[n+1];
    for (int i=0; i<=n; i++)
        BITree[i] = 0;
    for (int i=0; i<n; i++)
        updateBIT(BITree, n, i, arr[i]);
    // for (int i=1; i<=n; i++)
    //      cout << BITree[i] << " ";
    return BITree;
}
 
long long getSum(long long BITree[], int index) {
    long long sum = 0;
    index = index + 1;
    while (index>0) {
        sum += BITree[index];
        index -= index & (-index);
    }
    return sum;
}
 
void update(long long BITree[], int l, int r, int n, long long val) {
    updateBIT(BITree, n, l, val);
    updateBIT(BITree, n, r+1, -val);
}
 
int main() {
    freopen("in","r",stdin);
    ios::sync_with_stdio(false);
    long long T,nn,m,lbb,rbb,value,add;
    cin >> T;
    while(T--) {
        for(long long i=0; i<N; ++i) {
            q[i].tt=0;
            q[i].ll=0;
            q[i].rr=0;
        }
        cin >> nn >> m;
        long long c[m];
        for(int i=0; i<m; ++i) c[i]=1;
        long long *BITree = constructBITree(c,m);
        for(long long i=0; i<m; ++i)
            cin >> q[i].tt >> q[i].ll >> q[i].rr;
        for(long long i=m-1; i>=0; --i) {
            if(q[i].tt==2) {
                lbb = q[i].ll-1;
                rbb = q[i].rr-1;
                value = getSum(BITree,i);
                update(BITree,lbb,rbb,m,value);
            }
        }
        for(long long i=0; i<m; ++i) {
            if(q[i].tt==1) {
                add = getSum(BITree,i);
                a[q[i].ll-1] += add;
                a[q[i].rr] -= add;
            }
        }
        for(long long i=1; i<nn; ++i)
            a[i] = ((M*M + a[i])%M + a[i-1]%M)%M;
        for(long long i=0; i<nn; ++i)
            cout << a[i] << " ";
        cout << "\n";
    }
}