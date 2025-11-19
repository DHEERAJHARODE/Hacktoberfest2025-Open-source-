// Given two integers a and b. The task is to print
// sum of all the digits appearing in the
// integers between a and b


#include "bits/stdc++.h"
using namespace std;

// Memoization for the state results
long long dp[20][180][2];

// Stores the digits in x in a vector digit
long long getDigits(long long x, vector <int> &digit)
{
	while (x)
	{
		digit.push_back(x%10);
		x /= 10;
	}
}

// Return sum of digits from 1 to integer in
// digit vector
long long digitSum(int idx, int sum, int tight,
						vector <int> &digit)
{
	// base case
	if (idx == -1)
	return sum;

	// checking if already calculated this state
	if (dp[idx][sum][tight] != -1 and tight != 1)
		return dp[idx][sum][tight];

	long long ret = 0;

	// calculating range value
	int k = (tight)? digit[idx] : 9;

	for (int i = 0; i <= k ; i++)
	{
		// calculating newTight value for next state
		int newTight = (digit[idx] == i)? tight : 0;

		// fetching answer from next state
		ret += digitSum(idx-1, sum+i, newTight, digit);
	}

	if (!tight)
	dp[idx][sum][tight] = ret;

	return ret;
}

// Returns sum of digits in numbers from a to b.
int rangeDigitSum(int a, int b)
{
	// initializing dp with -1
	memset(dp, -1, sizeof(dp));

	// storing digits of a-1 in digit vector
	vector<int> digitA;
	getDigits(a-1, digitA);

	// Finding sum of digits from 1 to "a-1" which is passed
	// as digitA.
	long long ans1 = digitSum(digitA.size()-1, 0, 1, digitA);

	// Storing digits of b in digit vector
	vector<int> digitB;
	getDigits(b, digitB);

	// Finding sum of digits from 1 to "b" which is passed
	// as digitB.
	long long ans2 = digitSum(digitB.size()-1, 0, 1, digitB);

	return (ans2 - ans1);
}


int main()
{
	long long a = 123, b = 1024;
	cout << "digit sum for given range : "
		<< rangeDigitSum(a, b) << endl;
	return 0;
}
