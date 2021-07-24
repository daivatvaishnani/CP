#include <bits/stdc++.h>
using namespace std;
typedef long long int uli;
int nv;
void line(int len){
  int bef=1;
  for(int i=0;i<len;i++){
    printf("%d %d\n",bef,++nv);
    bef=nv;
  }
}
int main(){
  int t,n,d;
  scanf("%d",&t);
  while(t--){
    scanf("%d %d",&n,&d);
    if(n==2){
      if(d==1){
        puts("YES");
        puts("1 2");
      }
      else puts("NO");
      continue;
    }
    if(d==0){
      puts("YES");
      nv=1;
      if(n%2==0){
        puts("1 2");
        nv++;
        --n;
      }
      line((n-1)/2);
      line(n/2);
      continue;
    }
    if(n<4*d)puts("NO");
    else{
      puts("YES");
      nv=1;
      line(d);
      line(d);
      int a=2*d-1;
      a+=n-4*d;
      int u=nv;
      while(a--)printf("%d %d\n",u,++nv);
    }
  }
  return 0;
}
