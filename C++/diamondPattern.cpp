
#include <bits/stdc++.h>
using namespace std;

// Prints diamond pattern with 2n rows
void printDiamond(int n)
{
	int space = n - 1;

	// run loop (parent loop)
	// till number of rows
	for (int i = 0; i < n; i++)
	{
		// loop for initially space,
		// before star printing
		for (int j = 0;j < space; j++)
			cout << " ";

		// Print i+1 stars
		for (int j = 0; j <= i; j++)
			cout << "* ";

		cout << endl;
		space--;
	}

	// Repeat again in reverse order
	space = 0;

	// run loop (parent loop)
	// till number of rows
	for (int i = n; i > 0; i--)
	{
		// loop for initially space,
		// before star printing
		for (int j = 0; j < space; j++)
			cout << " ";

		// Print i stars
		for (int j = 0;j < i;j++)
			cout << "* ";

		cout << endl;
		space++;
	}
}

// Driver code
int main()
{
	int n;
    cin>>n;
    printDiamond(n);
	return 0;
}

