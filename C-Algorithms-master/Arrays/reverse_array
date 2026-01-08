// Iterative C program to reverse an array 
#include<stdio.h> 

/* Function to reverse arr[] from start to end*/
void rvereseArray(int arr[], int start, int end) 
{ 
	int temp; 
	while (start < end) 
	{ 
		temp = arr[start]; 
		arr[start] = arr[end]; 
		arr[end] = temp; 
		start++; 
		end--; 
	} 
}	 

/* Utility that prints out an array on a line */
void printArray(int arr[], int size) 
{ 
int i; 
for (i=0; i < size; i++) 
	printf("%d ", arr[i]); 

printf("\n"); 
} 

/* Driver function to test above functions */
int main() 
{ 
	int arr[] = {1, 2, 3, 4, 5, 6}; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	printArray(arr, n); 
	rvereseArray(arr, 0, n-1); 
	printf("Reversed array is \n"); 
	printArray(arr, n);	 
	return 0; 
} 
