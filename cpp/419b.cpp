#include <bits/stdc++.h>
using namespace std;
#define fio freopen("in","r",stdin);freopen("out","w",stdout)
#include <bits/stdc++.h>
using namespace std;
int n,k,q,a,b,ct;
const int MAX = 200000;
const int MAXN = 255557;
int s[MAXN];
int main() {
	scanf("%d %d %d", &n, &k, &q);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &a, &b);
		s[a]++;
		s[b + 1]--;
	}
	for (int i = 2; i <= MAX; i++)
		s[i] += s[i - 1];
	for (int i = 1; i <= MAX; i++)
		s[i] = s[i - 1] + (s[i] >= k);
	while (q--) {
		scanf("%d %d", &a, &b);
		printf("%d\n", s[b] - s[a - 1]);
	}	
}