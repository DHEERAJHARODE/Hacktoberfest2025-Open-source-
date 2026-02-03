#include <bits/stdc++.h>
using namespace std;

// returns true if there is triplet with sum equal
// to 'sum' present in A[]. Also, prints the triplet
bool find3Numbers(int A[], int arr_size, int sum)
{
	// Fix the first element as A[i]
	for (int i = 0; i < arr_size - 2; i++)
	{

		// Find pair in subarray A[i+1..n-1]
		// with sum equal to sum - A[i]
		unordered_set<int> s;
		int curr_sum = sum - A[i];
		for (int j = i + 1; j < arr_size; j++)
		{
			if (s.find(curr_sum - A[j]) != s.end())
			{
				printf("Triplet is %d, %d, %d", A[i],
					A[j], curr_sum - A[j]);
				return true;
			}
			s.insert(A[j]);
		}
	}

	// If we reach here, then no triplet was found
	return false;
}


int main()
{
	int A[] = { 1, 4, 45, 6, 10, 8 };
	int sum = 22;
	int arr_size = sizeof(A) / sizeof(A[0]);

	find3Numbers(A, arr_size, sum);

	return 0;
}
