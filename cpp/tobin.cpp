#include <iostream>
#include <string>

using namespace std;

string toBin (int val) {
	string bin;
	while (val != 0) {bin = (val%2==0 ? '0' : '1') + bin; val/=2;}
	return bin;
}

int exp(int a, int b) {int rs = 1; for(int i=1; i<=b; i++) {rs *= a;} return rs;}

int toInt(string binary) {
	int rs = 0;
	int len = binary.length()-1;
	int i=len;
	while(i >= 0) {
		rs += (binary[i]=='1' ? exp(2,len-i) : 0);
		i--;
	}
	return rs;
}

int main() {
	string s = "10001100110";
	cout << toBin(1126) << endl;
	cout << toInt("10001100110") << endl;
	return 0;
}