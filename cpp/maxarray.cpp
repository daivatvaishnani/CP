#include <iostream>
#include <cstdio>

using namespace std;

int maxarray(int array[], int size) {
	int max = 0;
	for(int i=0; i<size; i++) {max = (array[i] > max ? array[i] : max);}
	return max;
}

int main() {
	int array[] = {1,12,5,-10,6,7,9};
	cout << maxarray(array,7) <<endl;
}