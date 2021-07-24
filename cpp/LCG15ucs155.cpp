#include <bits/stdc++.h>

using namespace std;

#define MIN -9223372036854775800

vector<long double> LineraCongruentialGenerator(long long noOfRandoms, long long ranOfRandoms) {
	//Return vector of random numbers as per requirements.
	vector<long double> randoms;
	
	// Parameters of the Linear Congruential Generator taken from Numerical Recipies. (https://en.wikipedia.org/wiki/Linear_congruential_generator)
	long long multiplier = 	1664525;
	long long increment = 1013904223;
	long long modulus = pow(2,32);
	long long seed = 23579;
	
	long double random;
	// long double rand;

	for(int i=0; i<noOfRandoms; ++i) {
		random = (multiplier * seed + increment) % modulus;
		seed = random;
		random = (random / (modulus + 0.0) * ranOfRandoms);
		randoms.push_back(random);	
	}
	return randoms;
}

void Run_KolmogorovSmirnovTest(vector<long double> numbers, long double dAlpha) {
	sort(numbers.begin(), numbers.end());
	long double dPlus = MIN;
	long double dMinus = MIN;
	long long sizeOfNumbers = numbers.size(); 
	for(int i=0; i<sizeOfNumbers; ++i) {
		dPlus = max((i+1)/(sizeOfNumbers + 0.0) - (long double)numbers[i], dPlus);
		dMinus = max((long double)numbers[i] - (i)/(sizeOfNumbers + 0.0), dMinus);
	}

	cout << "The Kolmogorov-Smirnov test says :\n";
	cout << "D+ : " << dPlus << "\n";
	cout << "D- : " << dMinus << "\n";
	cout << "D-Alpha : " << dAlpha << "\n";
	dAlpha >= max(dPlus, dMinus) ? cout << "The null hypothesis is not rejected.\n" : cout << "The null hypothesis is rejected.\n"; 
}

void Run_ChiSquareTest(vector<long double> numbers, long long sampling, long long range, long double xNotSquareAlpha ) {
	long double div = range / (sampling + 0.0);
	int samples[sampling];
	for(int i=0; i<sampling; ++i) samples[i] = 0;
	for(int i=0; i<numbers.size(); ++i) ++samples[(long long) (numbers[i] / div)];
	long double Ei = numbers.size() / (sampling + 0.0);
	long double xNotSquare = 0; 
	for(int i=0; i<sampling; ++i) xNotSquare += ((samples[i]-Ei) * (samples[i]-Ei))/ (Ei + 0.0);

	cout << "The Chi-Square test says :\n";
	cout << "X^2 : " << xNotSquare << "\n";
	cout << "X-Alpha^2 : " << xNotSquareAlpha << "\n";	
	xNotSquareAlpha >= xNotSquare ? cout << "The null hypothesis is not rejected.\n" : cout << "The null hypothesis is rejected.\n";
}

int main() {
	long long numberOfRandoms = 100;
	long long rangeOfRandoms = 1;
	long long alpha = 0.05; // Acceptance value
	
	// Set of values for numberOfRandoms = 100, range = [0,1) & alpha = 0.05 ...
	long double DAlpha = 0.136;
	long long noOfClasses = 10; // Our Choice	
	long double XNotSquareAlpha = 16.9; 
	
	// Generate Random Numbers (Psuedo-Random Numbers) through a LCG ...
	vector<long double> randomNumbers = LineraCongruentialGenerator(numberOfRandoms, rangeOfRandoms);
	
	// For displaying the generated random numbers ... 
		// for(int i=0; i<randomNumbers.size(); ++i) cout << randomNumbers[i] << "\n";
	
	// For seeing the frequency-distribution of genearated Numbers ...
		// int frequency[rangeOfRandoms + 1];
		// for(int i=0; i<=rangeOfRandoms; ++i) frequency[i]=0;	
		// for(int i=0; i<randomNumbers.size(); ++i) ++frequency[(long long)randomNumbers[i]];
		// for(int i=0; i<=rangeOfRandoms; ++i) cout << i << " " << frequency[i] << "\n";

	// For testing the uniformity of Random-Numbers ...
		// The Kolmogorov-Smirnov Test : 
		Run_KolmogorovSmirnovTest(randomNumbers, DAlpha);
		
		cout << "\n";
		
		// The Chi-Square Test :
		Run_ChiSquareTest(randomNumbers, noOfClasses, rangeOfRandoms, XNotSquareAlpha);

}