#include <bits/stdc++.h>

using namespace std;

const long long N = 1e5;
const long long M = 1e9+7;

long long a[N+1], tree[4*N];    
long long T,n,m,lbb,rbb,value,add;
pair<long long, pair<long long, long long> > q[N];

#define t first
#define l second.first
#define r second.second

void modify(long long lb, long long rb, long long value) {
    for (lb += m, rb += m; lb < rb; lb >>= 1, rb >>= 1) {
        if (lb&1) {
            tree[lb] = (9*M*M+tree[lb]+value)%M;
            ++lb;
        }
        if (rb&1) {
            --rb;
            tree[rb] = (9*M*M+tree[rb]+value)%M;
        }
    }
}

long long query(long long p) {
    long long res = 0;
    for (p += m; p > 0; p >>= 1) {
        res = (9*M*M+res+tree[p])%M;
    }
    return res;
}

int main() {
	freopen("in","r",stdin);
    ios::sync_with_stdio(false);
    cin >> T;
    while(T--) {
        for(long long i=0; i<=N; ++i) a[i]=0;
        for(long long i=0; i<2*N; ++i) tree[i]=0;
        for(long long i=0; i<=N; ++i) {
            q[i].t=0;
            q[i].l=0;
            q[i].r=0;
        }
        cin >> n >> m;
        for(long long i=m; i<2*m; ++i) tree[i]=1;
        for(long long i=0; i<m; ++i)
            cin >> q[i].t >> q[i].l >> q[i].r;
        for(long long i=m-1; i>=0; --i) {
            if(q[i].t==2) {
                lbb = m+q[i].l-1;
                rbb = m+q[i].r;
                value = query(m+i);
                modify(lbb,rbb,value);
            }
        }
        for(long long i=0; i<m; ++i) {
            if(q[i].t==1) {
                add = query(m+i);
                if(a[q[i].l-1]<0) {
                    if(add>-a[q[i].l-1]) a[q[i].l-1] = (9*M*M+add+a[q[i].l-1])%M;
                    else a[q[i].l-1] = -((9*M*M-a[q[i].l-1]-add)%M);
                }
                else a[q[i].l-1] = (9*M*M+a[q[i].l-1]+add)%M;
                if(a[q[i].r]>0) {
                    if(add>a[q[i].r]) a[q[i].r] = -((9*M*M+add-a[q[i].r])%M);
                    else a[q[i].r] = (9*M*M+a[q[i].r]-add)%M;
                }
                else a[q[i].r] = -((9*M*M-a[q[i].r]+add)%M);
            }
        }
        for(long long i=1; i<n; ++i)
            a[i] = (9*M*M + a[i] + a[i-1])%M;
        for(long long i=0; i<n; ++i)
            cout << a[i] << " ";
        cout << "\n";
    }
}               