#include <bits/stdc++.h>
 
using namespace std;
 
vector< pair<int, pair<int,int> > > Q;
vector< pair< pair<int, int>, pair<int, int> > > QQ;
vector<long long> C;
long long A[100005];
const long long M = 1e9+7;
 
#define t first
#define l second.first
#define r second.second
#define id first.second
 
int main() {
	freopen("in","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T,m,n,ti,li,ri;
    cin >> T;
    while(T--) {
        Q.clear();
        C.clear();
        QQ.clear();
        for (int i = 0; i < 100005; ++i) A[i] = 0;
        cin >> n >> m;
        Q.push_back(make_pair(0, make_pair(0, 0))); // Zero Query
        QQ.push_back(make_pair(make_pair(0, 0), make_pair(0, 0)));
        C.push_back(0);    // Zero Count
        for (int i = 1; i <= m; ++i) {
            cin >> ti >> li >> ri;
            if (ti == 2) {
                QQ.push_back(make_pair(make_pair(ti, i), make_pair(li, ri)));
            }
            C.push_back(1);
            Q.push_back(make_pair(ti, make_pair(li, ri)));
        }
        int I;
        for (int i = QQ.size() - 1; i >= 0; --i) {
            I = QQ[i].id;
            for (int j = QQ[i].l; j <= QQ[i].r; ++j) {
                C[j] = C[j] + C[I];
                C[j]>M ? C[j]=C[j]-M : C[j]=C[j];
            }
        }
        for (int i = 1; i < Q.size(); ++i) {
            if (Q[i].t == 1) {
                A[Q[i].l] += C[i];
                A[Q[i].r + 1] -= C[i];
            }
        }
        for (int i = 1; i <= n; ++i) {
            A[i] = (M + A[i]%M + A[i - 1]%M) % M;
        }
        for(int i=1; i<=n; ++i) {
            cout << A[i] << " ";
        }
        cout << "\n";
    }
} 