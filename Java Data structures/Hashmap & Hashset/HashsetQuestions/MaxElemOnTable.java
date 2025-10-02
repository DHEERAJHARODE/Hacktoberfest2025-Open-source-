import java.util.*;

public class MaxElemOnTable {
    /*
     * Question - You are given a distinct pairs. Each pair is numbered from 1 to
     * n. All these pairs are initially put in a bag
     * You need to pair up each number. You take numbers one by one from the bag and
     * for each number you look whether the pair
     * of this number has already been taken out of bag, or not. If not (that means
     * the pair of this number is still in the bag),
     * you put the current number on the table in front of him. Otherwise, you put
     * both numbers from the pair aside. Print the
     * maximum of numbers that were on the table at the time.
     */
    public static int FindMaxNumOnTable(int[] arr) {
        HashSet<Integer> mp = new HashSet<>();
        int maxsize = 0;
        for (int i = 0; i < arr.length; i++) {
            if (mp.contains(arr[i])) {// if contains then we have to remove the element.......
                mp.remove(arr[i]);
            } else {
                mp.add(arr[i]);// if doesn't contain then we will put the element on the table and calculate
                               // the current size of the table......
                maxsize = Math.max(maxsize, mp.size());
            }
        }
        return maxsize;
    }

    public static void main(String[] args) {
        int[] arr = { 2, 1, 1, 3, 2, 3 };
        int ans = FindMaxNumOnTable(arr);
        System.out.println("The maximum number of numbers that were on the table is : " + ans);
    }
}
