## Optimized version of your code with improvements:

- Removed unnecessary header files.
- Used meaningful variable names.
- Simplified the sorting logic (bubble sort).
- Removed conio.h as it's outdated and non-standard.

#include <stdio.h>

void bubbleSort(int arr[], int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap elements
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of elements to sort: ");
    scanf("%d", &n);

    int arr[n];  // Dynamically size the array based on input
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    bubbleSort(arr, n);  // Call sorting function

    printf("The sorted array is:\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t", arr[i]);
    }
    
    return 0;
}
