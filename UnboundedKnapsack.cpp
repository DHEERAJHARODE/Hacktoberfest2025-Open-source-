#include <bits/stdc++.h>
using namespace std;

int unboundedKnapsack(int N, int W, int val[], int wt[])
{
	int t[N + 1][W + 1];
	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j <= W; j++)
		{
			t[i][0] = 0;
			t[0][j] = 0;

			if (wt[i - 1] <= j)
			{
				t[i][j] = max(t[i - 1][j], t[i][j - wt[i - 1]] + val[i - 1]);
			}
			else
			{
				t[i][j] = t[i - 1][j];
			}
		}
	}

	return t[N][W];
}
