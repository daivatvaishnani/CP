#include <bits/stdc++.h>

using namespace std;

enum Day {Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday};

void func(int& a, int& b) {
	++a;
	++b;
	return;
}

int main() {
	enum Day myday = Monday;
	if(myday == Monday) cout << "Day : " << (Day) myday << "\n";
	int a = 10, b = 15;
	float c = 0.1876;
	if(c == 0.1876) cout << "yes\n";
	// func(a, a);
	// cout << a << " " << b << "\n";
	// cout << "hello bitch!\n";
	return 0;
}
