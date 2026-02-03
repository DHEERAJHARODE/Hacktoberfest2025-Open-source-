#include <iostream>
using namespace std;

int binary(int arr[], int size, int element)		//function to implement binary search
{
	int low = 0;		 // Initialize low to the first index of the array.
	int high = size - 1; // Initialize high to the last index of the array.

	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (arr[mid] == element)
		{
			return mid;
		}
		else if (arr[mid] < element)
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}
	return -1;
}

int main()
{
	int arr[100], size, element, i;
	cout << "Enter the size of the array = ";
	cin >> size;
	for (int i = 0; i < size; i++)
	{
		cout << "Enter element no. " << i + 1 << endl;
		cin >> arr[i];
	}
	cout << "Entered array is : " << endl;
	for (int i = 0; i < size; i++)
	{

		cout << arr[i] <<" ";
	}
	cout<<endl;

	cout << "Enter the element that you want to search for = " << endl;
	cin >> element;

	// int size = sizeof(arr) / sizeof(arr[0]); // Use arr[0] to get the size of an element
	// int element = 82;
	int searchindex = binary(arr, size, element);  	// calling the binary() function
	cout << "Location = " << searchindex << endl;

	return 0;
}
