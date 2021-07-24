#include <bits/stdc++.h>
 
using namespace std;
 
int n, k;
vector<int> a[2505];
int c[2505];
 
int main(int argc, char *argv[]) {
   freopen("in","r",stdin); freopen("out","w",stdout);
   int t, x;
   cin >> t;
   while(t--){
      scanf("%d%d", &n, &k);
      for(int i = 0; i <= 2502; ++i){
         a[i].clear();
      }
      for(int i = 0; i < n; ++i){
         int l;
         scanf("%d", &l);
         for(int j = 0; j < l; ++j){
            scanf("%d", &x);
            a[i].push_back(x);
         }
      }
      int res1 = 0;
      for(int i = 0; i < n; ++i){
         for(int j = 0; j <= 2500; ++j){
            c[j] = 0;
         }
         for(int l = 0; l < a[i].size(); ++l){
            c[a[i][l]] = 1;
         }
         for(int j = i + 1; j < n; ++j){
            int c1 = a[i].size();
            for(int l = 0; l < a[j].size(); ++l){
               if(c[a[j][l]] == 0){
                  ++c1;
               }
            }
            if(c1 != k) ++res1;
         }
      }
      int res = ((n * (n - 1)) / 2) - res1;
      printf("%d\n", res);
   }
   return 0;
}