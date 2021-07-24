#include <iostream>

using namespace std;

int cnt=0;

void get_permutations (int b ,int large, int small, int sum) {
	int a;
	if(sum >7) {
		for(a=sum-large;a<=large;a++) { cnt++; (a!=b && b!=(sum-a) && (sum-a)!=a ? cout<<a<<b<<(sum-a)<<endl; : continue; }
	}
	else { 
		for(a=small;a<=sum-small;a++) { cnt++; (a!=b && b!=(sum-a) && (sum-a)!=a ? cout<<a<<b<<(sum-a)<<endl; : continue; }
	}
}	

void fps_problem (int small, int large, int sum) {
	int p=2;
	while(p<=large) {get_permutations(p, large, small, sum-p); p+=2;}
}

int main() {//(int argc, char const *argv[])

	fps_problem(1,7,12);
	cout<<cnt<<endl;

	return 0;
}