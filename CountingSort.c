#include <stdio.h>
#include <stdlib.h>

// Helper function to find the maximum value in an array
int find_max(int *arr, int size) {
    if (size <= 0) return -1;
    int max_val = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }
    return max_val;
}

/**
 * @brief Sorts an array of non-negative integers using the Counting Sort algorithm.
 *
 * @param arr The input array to be sorted.
 * @param sorted_arr The buffer to store the sorted array.
 * @param size The number of elements in the array.
 */
void countingSort(int *arr, int *sorted_arr, int size) {
    if (size <= 0) return;

    // Step 1: Find the maximum element to determine the range
    int max_val = find_max(arr, size);

    // Step 2: Create a count array and initialize to zero
    // calloc allocates and zeroes out the memory
    int *count_array = (int *)calloc(max_val + 1, sizeof(int));
    if (count_array == NULL) {
        perror("Failed to allocate memory for count array");
        return;
    }

    // Step 3: Store the frequency of each element
    for (int i = 0; i < size; i++) {
        count_array[arr[i]]++;
    }

    // Step 4: Store the cumulative count of each element
    // This will give us the final position of the elements
    for (int i = 1; i <= max_val; i++) {
        count_array[i] += count_array[i - 1];
    }

    // Step 5: Build the sorted array by placing elements in their correct
    // positions. We iterate backwards to make the sort stable.
    for (int i = size - 1; i >= 0; i--) {
        sorted_arr[count_array[arr[i]] - 1] = arr[i];
        count_array[arr[i]]--;
    }
    
    // Clean up the dynamically allocated count array
    free(count_array);
}

int main() {
    int *array, *sorted_array;
    int i, size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);
    
    if (size <= 0) {
        printf("Array size must be positive.\n");
        return 1;
    }

    // Allocate memory for the input and output arrays
    array = (int *)malloc(size * sizeof(int));
    sorted_array = (int *)malloc(size * sizeof(int));
    
    if (array == NULL || sorted_array == NULL) {
        perror("Failed to allocate memory");
        free(array); // free even if sorted_array failed
        free(sorted_array);
        return 1;
    }

    printf("Enter the elements (non-negative integers):\n");
    for (i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    printf("\nUnsorted array:\n");
    for (i = 0; i < size; i++) {
        printf("%d\t", array[i]);
    }

    countingSort(array, sorted_array, size);

    printf("\n\nSorted array:\n");
    // BUG FIX: The loop should go from 0 to size-1
    for (i = 0; i < size; i++) {
        printf("%d\t", sorted_array[i]);
    }
    printf("\n");
    
    // MEMORY LEAK FIX: Free the allocated memory
    free(array);
    free(sorted_array);

    return 0;
}
