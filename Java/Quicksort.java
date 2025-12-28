import java.util.Arrays;

public class QuickSort {

    // Function to perform the quicksort
    public static void quicksort(int[] array, int low, int high) {
        if (low < high) {
            // Partition the array and get the pivot index
            int pivotIndex = partition(array, low, high);
            
            // Recursively apply quicksort to the left and right partitions
            quicksort(array, low, pivotIndex - 1);
            quicksort(array, pivotIndex + 1, high);
        }
    }

    // Function to partition the array
    private static int partition(int[] array, int low, int high) {
        // Choose the last element as the pivot
        int pivot = array[high];
        int i = low - 1; // Pointer for greater element

        // Traverse through all elements
        for (int j = low; j < high; j++) {
            // If current element is smaller than the pivot
            if (array[j] < pivot) {
                i++;
                // Swap element at i with element at j
                swap(array, i, j);
            }
        }

        // Swap the pivot element with the element at i + 1
        swap(array, i + 1, high);
        return i + 1; // Return the pivot index
    }

    // Function to swap two elements
    private static void swap(int[] array, int i, int j) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    // Main method to test the quicksort algorithm
    public static void main(String[] args) {
        int[] array = { 34, 7, 23, 32, 5, 62, 14 };
        System.out.println("Original array: " + Arrays.toString(array));

        // Apply quicksort
        quicksort(array, 0, array.length - 1);

        System.out.println("Sorted array: " + Arrays.toString(array));
    }
}
