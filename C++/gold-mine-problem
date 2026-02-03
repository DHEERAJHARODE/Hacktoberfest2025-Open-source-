// C++ program to solve Gold Mine problem
#include<bits/stdc++.h>
using namespace std;

int collectGold(vector<vector<int>> gold, int x, int y, int n, int m) {

	// Base condition.
	if ((x < 0) || (x == n) || (y == m)) {
		return 0;
	}


	// Right upper diagonal
	int rightUpperDiagonal = collectGold(gold, x - 1, y + 1, n, m);

	// right
	int right = collectGold(gold, x, y + 1, n, m);

	// Lower right diagonal
	int rightLowerDiagonal = collectGold(gold, x + 1, y + 1, n, m);

	// Return the maximum and store the value
	return gold[x][y] + max(max(rightUpperDiagonal, rightLowerDiagonal), right);
}

int getMaxGold(vector<vector<int>> gold, int n, int m)
{
	int maxGold = 0;

	for (int i = 0; i < n; i++) {

		// Recursive function call for ith row.
		int goldCollected = collectGold(gold, i, 0, n, m);
		maxGold = max(maxGold, goldCollected);
	}

	return maxGold;
}

// Driver Code
int main()
{
	vector<vector<int>> gold { {1, 3, 1, 5},
		{2, 2, 4, 1},
		{5, 0, 2, 3},
		{0, 6, 1, 2}
	};
	int m = 4, n = 4;
	cout << getMaxGold(gold, n, m);
	return 0;
}
