// C++ program to find 4 elements
// with given sum
#include <bits/stdc++.h>
using namespace std;

// The following structure is needed
// to store pair sums in aux[]
class pairSum {
public:
	// index (int A[]) of first element in pair
	int first;

	// index of second element in pair
	int sec;

	// sum of the pair
	int sum;
};

// Following function is needed
// for library function qsort()
int compare(const void* a, const void* b)
{
	return ((*(pairSum*)a).sum - (*(pairSum*)b).sum);
}

// Function to check if two given pairs
// have any common element or not
bool noCommon(pairSum a, pairSum b)
{
	if (a.first == b.first || a.first == b.sec
		|| a.sec == b.first || a.sec == b.sec)
		return false;
	return true;
}

// The function finds four
// elements with given sum X
void findFourElements(int arr[], int n, int X)
{
	int i, j;

	// Create an auxiliary array
	// to store all pair sums
	int size = (n * (n - 1)) / 2;
	pairSum aux[size];

	// Generate all possible pairs
	// from A[] and store sums
	// of all possible pairs in aux[]
	int k = 0;
	for (i = 0; i < n - 1; i++) {
		for (j = i + 1; j < n; j++) {
			aux[k].sum = arr[i] + arr[j];
			aux[k].first = i;
			aux[k].sec = j;
			k++;
		}
	}

	// Sort the aux[] array using
	// library function for sorting
	qsort(aux, size, sizeof(aux[0]), compare);

	// Now start two index variables
	// from two corners of array
	// and move them toward each other.
	i = 0;
	j = size - 1;
	while (i < size && j >= 0) {
		if ((aux[i].sum + aux[j].sum == X)
			&& noCommon(aux[i], aux[j])) {
			cout << arr[aux[i].first] << ", "
				<< arr[aux[i].sec] << ", "
				<< arr[aux[j].first] << ", "
				<< arr[aux[j].sec] << endl;
			return;
		}
		else if (aux[i].sum + aux[j].sum < X)
			i++;
		else
			j--;
	}
}

// Driver code
int main()
{
	int arr[] = { 10, 20, 30, 40, 1, 2 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int X = 91;

	// Function Call
	findFourElements(arr, n, X);
	return 0;
}

// This is code is contributed by rathbhupendra
