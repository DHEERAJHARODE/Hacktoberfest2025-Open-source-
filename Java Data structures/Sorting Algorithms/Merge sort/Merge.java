public class Merge {
    public static void MergeArr(int[] arr, int l, int mid, int r) {
        int n1 = mid - l + 1;
        int n2 = r - mid;
        int[] left = new int[n1];
        int[] right = new int[n2];
        for (int i = 0; i < n1; i++) {
            left[i] = arr[l + i];
        }
        for (int j = 0; j < n2; j++) {
            right[j] = arr[mid + j + 1];
        }
        int i = 0;
        int j = 0;
        int k = l;
        while (i < n1 && j < n2) {
            if (left[i] < right[j]) {
                arr[k] = left[i];
                i++;
                k++;
            } else {
                arr[k] = right[j];
                k++;
                j++;
            }
        }
        while (i < n1) {// for filling remain elements....if any...............
            arr[k] = left[i];
            k++;
            i++;
        }
        while (j < n2) {// for filling remain elements....if any...............
            arr[k] = right[j];
            k++;
            j++;
        }
    }

    public static void SortMerge(int[] arr, int l, int r) {
        if (l == r) {
            return;
        }
        int mid = (l + r) / 2;
        SortMerge(arr, l, mid);
        SortMerge(arr, mid + 1, r);
        MergeArr(arr, l, mid, r);
    }

    public static void main(String[] args) {
        int[] arr = { 6, 5, 4, 3, 2, 1 };
        int n = arr.length;
        SortMerge(arr, 0, n - 1);
        for (int elem : arr) {
            System.out.println(elem);
        }
    }
}
