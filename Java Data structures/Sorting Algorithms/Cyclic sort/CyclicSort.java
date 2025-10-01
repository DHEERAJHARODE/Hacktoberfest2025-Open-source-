public class CyclicSort {
    public static void SortCyclic(int[] arr) {
        int i = 0;
        while (arr[i] != i) {// Cyclic sort algorithm.............
            int temp = arr[i];
            arr[i] = arr[temp];
            arr[temp] = temp;
        }
    }

    public static void main(String[] args) {
        int[] arr = { 5, 3, 2, 0, 4, 1 };
        SortCyclic(arr);
        for (int i : arr)
            System.out.print(i + " ");
    }
}
