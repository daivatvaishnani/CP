#include <bits/stdc++.h>
using namespace std;
long double cal(int n, long double k, long double pos){
    if(n==1){return (pos+k);}
    else{
        if((unsigned long long)k%2==0){
            n-=1;
            k/=2;
            cal(n, k, pos);
        }
        else{
            k = ((k+1)/2)-1;
            n-=1;
            pos += (long double)pow(2, n);
            cal(n, k, pos);
        }
    }
   
}


int main() {
    freopen("in","r",stdin);
    int q, n;
    cin >>q;
   
    long double k, pos =0, ou;
   
    for(int i=0; i<q; i++){
        cin >> n >> k;
        pos =0;
       
        ou = cal(n, k, pos);
        cout << ou << endl;
    }
   
    return 0;
}