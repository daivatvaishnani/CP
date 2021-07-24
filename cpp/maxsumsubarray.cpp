#include <iostream>
#include <vector>

using namespace std;


// int countSum (int startIndex, int endIndex) {
// 	int sum =0;
// 	for(int i=startIndex;i<=endIndex;i++) {sum+=array[i];} return sum; 
// }

// int maxSubArraySum () {										//chutiya algo O(n**3)
// 	int sum=0,tmpsum=0;
// 	for(int i=0; i<arraysize; i++) {
// 		for(int j=i+1; j<arraysize; j++) {
// 			tmpsum = countSum(i,j);
// 			if(tmpsum > sum) sum=tmpsum;
// 		}
// 	}
// 	return sum;
// }
int	array[] = {-2, -3, 4, -1, -2, 1, 5, -3};
int arraysize = sizeof(array)/sizeof(array[0]);

int maxSubArraySum() {											// good algo O(n)
	int maxsofar = array[0];
	int currmax = array[0];

	for(int i=1; i<arraysize; i++) { currmax = (array[i] > currmax+array[i] ? array[i] : currmax+array[i]) ; maxsofar = (currmax > maxsofar ? currmax : maxsofar); }
	return maxsofar;
}

int main() {
	cout << maxSubArraySum() << endl;
	return 0;
}