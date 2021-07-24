#include <bits/stdc++.h>
using namespace std;
#define fio freopen("in","r",stdin);freopen("out","w",stdout)
#define fastio ios_base::sync_with_stdio(false)
#define rep(i, a, b)    for (__typeof (b) i = (a) ; i <= b ; ++i)
#define repstl(i, s) for (__typeof ((s).end ()) i = (s).begin (); i != ((s).end()) ; ++i)

const int N=1e6+55;
const int maxx=1e6,maxn=1e5;
int a[N+1],s[N+1];
int preorder[N+1];
bool prime[N+1];
int n,q,l,r,x,y,result,number,exponent;

void Sieve(int n) {
    memset(prime, true, sizeof(prime));
    memset(s, 1, sizeof(s));
    for (int p=2; p*p<=n; p++) {
        if (prime[p] == true) {
        	s[p]=p;
            for (int i=p*2; i<=n; i += p) {
                prime[i] = false;
            	s[i]=p;
            }	
        }
    }
}

int gpf(int n, int X, int Y) {											// Log(n) approach
	// cout<<"Factor"<<"	"<<"Power"<<"	"<<"Divisions\n";
	int curr = s[n];
	int cnt = 1;
	int tot=0;
	while(n>1) {
		n/=s[n];
		if(curr==s[n]) {
			cnt++;
			continue;
		}
		if(curr<=Y && curr>=X) {
			tot+=cnt;
			// cout<<curr<<"		"<<cnt<<"		"<<tot<<"\n";
		}
		curr=s[n];
		cnt=1;
	}
	return tot;
}

bool isPrime(int n) {
	if(prime[n])
		return true;
	else return false;
}

int F2(int L,int R,int X,int Y) {							// NLogN approach
    result=0;
   	result=preorder[R]-preorder[L-1];
    return result;
}

int main() {
	fio;
	fastio;
	Sieve(N);
	cin>>n;
	for(int i=1; i<=n; i++) {cin>>a[i];}
	for(int i=1; i<=n; i++) {
		preorder[i] = preorder[i-1] + gpf(a[i],2,a[i]);
	}
	cin>>q;
	while(q--) {
		cin>>l>>r>>x>>y;
		int max=0;
		cout<<F2(l,r,x,y);
		if(q>=1) 
			cout<<"\n";
	}	
}