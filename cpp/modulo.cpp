#include <iostream>

using namespace std;

 int modulo(int x){
 	int N = 1000000007;
    return (x % N + N) %N;
}

int main () {
	cout << modulo(7);
}