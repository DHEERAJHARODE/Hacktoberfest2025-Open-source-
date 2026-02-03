/*
In Josephus problem, n people are standing in a circle waiting to be executed and in every iteration, we kill the kth person and remove that person from the circle.

This procedure is repeated with the remaining people, starting with the (k+1)th person going in the same direction and killing the kth person, until only one person remains and is not killed.

We have to find the survivor position in the initial circle–given n the number of people standing in the circle initially and k the kth person to be executed.

JosephusProblem(n, k)– represents this problem.

JosephusProblem(8, 2)– 8 people are standing in a circle and in every iteration we kill the 2nd person.

First of all, the person at position 2 is killed, then the person at position 4 is killed, then the person at position 6 is killed then the person at position 8 is killed. , Then the persons at positions 3, 5, 7 are killed. So the person at position 1 survives.
*/


#include <bits/stdc++.h>
using namespace std;

int josephus(int n, int k)
{
	if (n == 1)
		return 1;
	else
		return (josephus(n - 1, k) + k - 1) % n + 1;
}

int main()
{
	int n = 8;
	int k = 2;
	cout << "The survivor position is " << josephus(n, k) << endl;
	return 0;
}
