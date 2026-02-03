#include <bits/stdc++.h>
using namespace std;


// recursive function to find GCD using Euclid Algorithm
int gcd(int a, int b)
{
	if (a == 0)
		return b;
	return gcd(b % a, a);
}


int main()
{
	int a = 10, b = 15;

	// Some Example
	cout << "GCD(" << a << ", " << b << ") = " << gcd(a, b)
		<< endl;
	a = 35, b = 10;
	cout << "GCD(" << a << ", " << b << ") = " << gcd(a, b)
		<< endl;
	a = 31, b = 2;
	cout << "GCD(" << a << ", " << b << ") = " << gcd(a, b)
		<< endl;
	return 0;
}
