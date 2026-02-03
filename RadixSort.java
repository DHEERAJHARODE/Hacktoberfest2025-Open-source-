import java.util.Arrays;

public class RadixSort {
    public static void main(String[] args) {
        int[] arr = {170, 45, 75, 90, 802, 24, 2, 66};
        radixSort(arr);

        System.out.println("Sorted array:");
        for (int num : arr) {
            System.out.print(num + " ");
        }
    }

    public static void radixSort(int[] arr) {
        int max = Arrays.stream(arr).max().getAsInt();
        int exp = 1;

        while (max / exp > 0) {
            countingSortByDigit(arr, exp);
            exp *= 10;
        }
    }

    public static void countingSortByDigit(int[] arr, int exp) {
        int n = arr.length;
        int[] output = new int[n];
        int[] count = new int[10]; // 0 to 9 for base 10

        // Initialize count array
        Arrays.fill(count, 0);

        // Count occurrences of each digit
        for (int i = 0; i < n; i++) {
            int digit = (arr[i] / exp) % 10;
            count[digit]++;
        }

        // Adjust the count array
        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }

        // Build the output array
        for (int i = n - 1; i >= 0; i--) {
            int digit = (arr[i] / exp) % 10;
            output[count[digit] - 1] = arr[i];
            count[digit]--;
        }

        // Copy the sorted output array back to the original array
        System.arraycopy(output, 0, arr, 0, n);
    }
}
