#include <bits/stdc++.h>
using namespace std;

int a[30], cnt;
int place(int pos)
{
	int i;
	for (i = 1; i < pos; i++) {
		if ((a[i] == a[pos])
			|| ((abs(a[i] - a[pos]) == abs(i - pos))))
			return 0;
	}
	return 1;
}

void print_solution(int N)
{
	int i, j;
	cnt++;
	cout << "\n\nSolution " << cnt <<endl;
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			if (a[i] == j)
				cout << "Q\t";
			else
				cout << "*\t";
		}
		cout << endl;
	}
}

void four_queen(int n)
{
	cnt = 0;
	int k = 1;
	a[k] = 0;
	while (k != 0) {
		a[k] = a[k] + 1;
		while ((a[k] <= n) && !place(k))
			a[k]++;
		if (a[k] <= n) {
			if (k == n)
				print_solution(n);
			else {
				k++;
				a[k] = 0;
			}
		}
		else
			k--;
	}
}

int main()
{
	int N = 4;
	four_queen(N);
	return 0;
}
