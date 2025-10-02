// public class Binary {
//     public static boolean SearchBinary(int[] arr, int targ) {
//         int st = 0;
//         boolean ans = false;
//         int end = arr.length - 1;
//         while (st <= end) {
//             int midpoint = (st + end) / 2;
//             if (arr[midpoint] == targ) {
//                 ans = true;
//                 return ans;
//             } else if (arr[midpoint] < targ)
//                 st = midpoint + 1;
//             else
//                 end = midpoint - 1;
//         }
//         return ans;
//     }

//     public static void main(String[] args) {
//         int[] arr = { 5, 3, 76, 8, 45, 3, 2, 3, 56 };
//         boolean ans = SearchBinary(arr, 2);
//         System.out.println(ans);
//     }
// }
public class Binary {
    public static boolean searchBinary(int[] arr, int targ) {
        int st = 0;
        int end = arr.length - 1;
        while (st <= end) {
            int midpoint = (st + end) / 2;
            if (arr[midpoint] == targ) {
                return true;
            } else if (arr[midpoint] < targ)
                st = midpoint + 1;
            else
                end = midpoint - 1;
        }
        return false;
    }

    public static void main(String[] args) {
        int[] arr = { 2, 4, 8, 9, 23, 71, 432, 567, 864 };
        boolean ans = searchBinary(arr, 8);
        System.out.println(ans);
    }
}
