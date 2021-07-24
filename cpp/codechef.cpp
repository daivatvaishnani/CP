#include <iostream>
#include <string>

using namespace std;

// int maxcontcnt(string s, char c) {
// 	int max=0,count=0;
// 	for(int i=0; i<s.size(); i++) {
// 		if(s[i]==c) {count++; max = (max > count ? max : count);}
// 		else {count=0;}
// 	}
// 	return max;
// }

int main() {
	int cases,n,m,x,y,size;
	string s;
	cin >> cases;
	while(cases!=0) {
		cin >> n >> m;
		cin >> s;
		size = s.size();
		bool status = false;
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				x=m,y=n;
				for(int k=0;k<size;k++) {
					if(s[k] == 'L') {
						x++; 
						if(x>=m) {
							status = true;
						}
					}
					if(s[k] == 'R') {
						x--; 
						if(x<0) {
							status = true;
						}
					}
					if(s[k] == 'U') {
						y--; 
						if(y<0) {
							status = true;
						}
					}
					if(s[k] == 'D') {
						y++; 
						if(y>=n) {
							status = true;
						}
					}
				}
			}
		}
		if(status == false) {cout << "safe" << endl;}
		else {cout << "unsafe" << endl;}
		cases--;
	}	
	return 0;
} 