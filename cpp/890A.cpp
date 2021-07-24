#include <bits/stdc++.h>

using namespace std;

#define msg(s) cout << #s << " : " << s << "\n"
#define fio freopen("in", "r", stdin); freopen("out", "w", stdout)
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define loop(n) int n; cin >> n; while(n--)
#define Loop(n) while(n--)
#define rep(i, a, b)    for (__typeof (a) i = (a) ; i <= b ; ++i)
#define rrep(i, a, b)   for (__typeof (a)i = (b) ; i >= a ; --i)
#define repstl(i, s) for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define empty empty()
#define size size()
#define clear clear()
#define pi acos(-1.0)
#define pb push_back
#define pf push_front
#define mp make_pair
#define ff first
#define ss second

typedef long long ll;
typedef long double lf;
typedef std::vector<int> vi;
typedef std::vector<char> vc;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int> > piii;

std::vector<int> v;
	
int main() {
	fastio;
	//fio;
	int val;
	rep(i, 1, 6) {
		cin >> val;
		v.pb(val);
	
	}
	int sum = 0;
	rep(i, 0, 5) {
		sum += v[i];
	} 
	rep(i, 0, 5) {
		rep(j, 0, 5) {
			rep(k, 0, 5) {
				if(i != j && i != k && j != k && 2*v[i] + 2*v[j] + 2*v[k] == sum) {
					cout << "YES\n";
					return 0;
				}
			}
		}
	}
	cout << "NO\n";
    return 0;
}