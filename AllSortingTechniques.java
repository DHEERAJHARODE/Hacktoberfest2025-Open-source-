import java.util.*;

public class AllSortingTechniques {

    // ---------- Bubble Sort ----------
    static void bubbleSort(int arr[]) {
        int n = arr.length;
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    // ---------- Selection Sort ----------
    static void selectionSort(int arr[]) {
        int n = arr.length;
        for (int i = 0; i < n - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[minIndex])
                    minIndex = j;
            }
            int temp = arr[minIndex];
            arr[minIndex] = arr[i];
            arr[i] = temp;
        }
    }

    // ---------- Insertion Sort ----------
    static void insertionSort(int arr[]) {
        for (int i = 1; i < arr.length; i++) {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }

    // ---------- Merge Sort ----------
    static void mergeSort(int arr[], int left, int right) {
        if (left < right) {
            int mid = (left + right) / 2;
            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);
            merge(arr, left, mid, right);
        }
    }

    static void merge(int arr[], int left, int mid, int right) {
        int n1 = mid - left + 1, n2 = right - mid;
        int L[] = new int[n1];
        int R[] = new int[n2];
        for (int i = 0; i < n1; i++) L[i] = arr[left + i];
        for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) arr[k++] = L[i++];
            else arr[k++] = R[j++];
        }
        while (i < n1) arr[k++] = L[i++];
        while (j < n2) arr[k++] = R[j++];
    }

    // ---------- Quick Sort ----------
    static void quickSort(int arr[], int low, int high) {
        if (low < high) {
            int pi = partition(arr, low, high);
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }

    static int partition(int arr[], int low, int high) {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;
        return i + 1;
    }

    // ---------- Heap Sort ----------
    static void heapSort(int arr[]) {
        int n = arr.length;
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(arr, n, i);
        for (int i = n - 1; i > 0; i--) {
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;
            heapify(arr, i, 0);
        }
    }

    static void heapify(int arr[], int n, int i) {
        int largest = i, l = 2 * i + 1, r = 2 * i + 2;
        if (l < n && arr[l] > arr[largest]) largest = l;
        if (r < n && arr[r] > arr[largest]) largest = r;
        if (largest != i) {
            int swap = arr[i];
            arr[i] = arr[largest];
            arr[largest] = swap;
            heapify(arr, n, largest);
        }
    }

    // ---------- Counting Sort ----------
    static void countingSort(int arr[]) {
        int max = Arrays.stream(arr).max().getAsInt();
        int count[] = new int[max + 1];
        for (int num : arr) count[num]++;
        int index = 0;
        for (int i = 0; i <= max; i++)
            while (count[i]-- > 0)
                arr[index++] = i;
    }

    // ---------- Radix Sort ----------
    static void radixSort(int arr[]) {
        int max = Arrays.stream(arr).max().getAsInt();
        for (int exp = 1; max / exp > 0; exp *= 10)
            countSortByDigit(arr, exp);
    }

    static void countSortByDigit(int arr[], int exp) {
        int n = arr.length;
        int output[] = new int[n];
        int count[] = new int[10];

        for (int i = 0; i < n; i++)
            count[(arr[i] / exp) % 10]++;

        for (int i = 1; i < 10; i++)
            count[i] += count[i - 1];

        for (int i = n - 1; i >= 0; i--) {
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }

        for (int i = 0; i < n; i++)
            arr[i] = output[i];
    }

    // ---------- Bucket Sort ----------
    static void bucketSort(float arr[]) {
        int n = arr.length;
        @SuppressWarnings("unchecked")
        Vector<Float>[] buckets = new Vector[n];
        for (int i = 0; i < n; i++)
            buckets[i] = new Vector<>();
        for (float v : arr)
            buckets[(int) (v * n)].add(v);
        for (int i = 0; i < n; i++)
            Collections.sort(buckets[i]);
        int index = 0;
        for (int i = 0; i < n; i++)
            for (float num : buckets[i])
                arr[index++] = num;
    }

    // ---------- Print Array ----------
    static void printArray(int arr[]) {
        for (int num : arr) System.out.print(num + " ");
        System.out.println();
    }

    static void printArray(float arr[]) {
        for (float num : arr) System.out.print(num + " ");
        System.out.println();
    }

    // ---------- Main Menu ----------
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter number of elements:");
        int n = sc.nextInt();
        int arr[] = new int[n];
        System.out.println("Enter " + n + " elements:");
        for (int i = 0; i < n; i++) arr[i] = sc.nextInt();

        System.out.println("\nChoose Sorting Algorithm:");
        System.out.println("1. Bubble Sort");
        System.out.println("2. Selection Sort");
        System.out.println("3. Insertion Sort");
        System.out.println("4. Merge Sort");
        System.out.println("5. Quick Sort");
        System.out.println("6. Heap Sort");
        System.out.println("7. Counting Sort");
        System.out.println("8. Radix Sort");
        System.out.println("9. Bucket Sort (for floats)");
        System.out.print("Enter choice: ");
        int choice = sc.nextInt();

        switch (choice) {
            case 1: bubbleSort(arr); break;
            case 2: selectionSort(arr); break;
            case 3: insertionSort(arr); break;
            case 4: mergeSort(arr, 0, n - 1); break;
            case 5: quickSort(arr, 0, n - 1); break;
            case 6: heapSort(arr); break;
            case 7: countingSort(arr); break;
            case 8: radixSort(arr); break;
            case 9:
                float[] farr = new float[n];
                for (int i = 0; i < n; i++) farr[i] = (float) arr[i] / 100; // convert for demo
                bucketSort(farr);
                System.out.println("Sorted array:");
                printArray(farr);
                return;
            default:
                System.out.println("Invalid choice!");
                return;
        }

        System.out.println("Sorted array:");
        printArray(arr);
        sc.close();
    }
}
