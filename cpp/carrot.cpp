#include <iostream>

using namespace std;

int main() {
	float n,t,k,d,left,time,time2;
	cin >> n >> t >> k >> d;
	
	if(n>k) {time = n/k*t;}
	else {time = t;}
	
	if(d>=time) {cout << "NO" << endl;}

	else {
		left = n-(d*k)/t;
		cout << (left/k > 1 ? "YES" : "NO") << endl; 
	}

	return 0;
}