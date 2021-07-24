#include <iostream>
using namespace std;

int max3 (int goldup,int goldrit, int golddwn) {
	return (goldrit > goldup ? goldrit : goldup) < golddwn ? golddwn : (goldrit > goldup ? goldrit : goldup);
}

int main() {
	cout << max3(115,20,10);
	return 0;
}