#include <iostream>
#include <string>

using namespace std;

int main() {
	int T;
	cin >> T;
	while(T) {
		string s;
		cin >> s;
		int stage=0;
		bool valid=false,box=false;
		int i=0, N = s.length();
		cout << N;
		while(i<N) {
			if(s[i]=='C') {
				if(box==false) {
					stage=1;
					valid=true;
					box=true;
				}
				else if (box==true && stage==1) {continue;}
				else {
					valid=false;
					break;
				}
			}
			else if(s[i]='E') {
				if(box==true && stage==1) {
					stage=2;
					valid=true;
				}
				else if(box==true && stage==2){continue;}
				else {
					valid=false;
					break;
				}
			}
			else {
				if(box==true && stage==2) {
					stage=3;
					valid=true;
					box=false;
				}
				else if(stage==3) {continue;}
				else {
					valid=false;
					break;
				}				
			} 
			i++;
		}
		cout << (valid==true ? "YES" : "NO") << endl;
		T--;
	}
	return 0;
}