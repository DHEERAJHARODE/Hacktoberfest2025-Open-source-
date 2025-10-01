public class FirstOcc {
    static int Occurence(int[] arr, int x) {
        int st = 0;
        int end = arr.length - 1;
        int firstocc = -1;
        if (arr[0] == x)// both code will work......................my code easily
            // understandable.........
            return 0;
        else {
            while (st <= end) {
                int mid = st + ((end - st) / 2);
                if (arr[mid] == x && arr[mid - 1] < x) {
                    return mid;
                } else if (arr[mid] > x)
                    end = mid - 1;
                else {
                    st = st + 1;
                }
            }
        }
        // while (st <= end) {
        // int mid = st + ((end - st) / 2);
        // if (arr[mid] == x) {
        // firstocc = mid;
        // end = mid - 1;
        // } else if (arr[mid] > x)
        // end = mid - 1;
        // else
        // st = st + 1;
        // }
        return firstocc;
    }

    public static void main(String[] args) {
        int[] arr = { 2, 4 };
        int x = 2;
        System.out.println(Occurence(arr, x));
    }
}
