#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string toBinary (int val) {
	string tmp;
	while(val!=0) {tmp = (val%2 ==0 ? '0':'1') +tmp; val=val/2;}
	return tmp;
}

int main() {

	cout << toBinary(26) << endl;
	return 0;
}
