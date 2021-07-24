#include <bits/stdc++.h>
using namespace std;
#define fio freopen("in","r",stdin);freopen("out","w",stdout)
int hh,mm,ret;
int main() {
	// fio;
	scanf("%d : %d", &hh,&mm);
	ret = 0;
	while((hh/10 != mm%10) || (hh%10 != mm/10)) {
		++mm;
		if(mm==60) {
			mm=0;
			++hh;
		}
		if(hh==24)
			hh=0;			
		++ret;
	}
	cout<<ret;
}