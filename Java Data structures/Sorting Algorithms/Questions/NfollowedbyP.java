public class NfollowedbyP {// In this method we will only place Negative and positive numbers we won't sort
                           // them we will only place them...
    static void ReplaceNansP(int[] arr) {
        int l = 0;
        int r = arr.length - 1;
        while (l < r) {
            while (arr[l] < 0)
                l++;
            while (arr[r] > 0)
                r--;
            if (l < r) {
                int temp = arr[l];
                arr[l] = arr[r];
                arr[r] = temp;
                l++;
                r--;
            }
        }
    }

    public static void main(String[] args) {
        int[] arr = { 13, -63, 2, 57, -8, 35, -9, 49, -86 };
        ReplaceNansP(arr);
        for (int i : arr)
            System.out.print(i + " ");
    }
}
