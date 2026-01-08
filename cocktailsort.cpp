#include <bits/stdc++.h>
using namespace std;

void cocktail_sort(vector<int>& arr) {
	int n = arr.size();
	bool swapped = true;
	int start = 0;
	int end = n - 1;
	while (swapped) {
		// Move from left to right
		swapped = false;
		for (int i = start; i < end; i++) {
			if (arr[i] > arr[i + 1]) {
				swap(arr[i], arr[i + 1]);
				swapped = true;
			}
		}
		if (!swapped) {
			break;
		}
		end--;
		// Move from right to left
		swapped = false;
		for (int i = end - 1; i >= start; i--) {
			if (arr[i] > arr[i + 1]) {
				swap(arr[i], arr[i + 1]);
				swapped = true;
			}
		}
		start++;
	}
}

int main() {
	vector<int> arr = {5, 2, 9, 3, 7, 6};
	cocktail_sort(arr);
	for (auto x : arr) {
		cout << x << " ";
	}
	cout << endl;
	return 0;
}
