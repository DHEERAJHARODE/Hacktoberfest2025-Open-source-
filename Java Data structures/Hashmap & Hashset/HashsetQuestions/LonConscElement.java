import java.util.HashSet;

public class LonConscElement {
    static int FindLonconsc(int[] arr) {// This code is to find the largest Subarray that have the consecutive elements
                                        // means ex. 1,2,3......in increasing 1 in order...........
        HashSet<Integer> mp = new HashSet<>();
        for (int i = 0; i < arr.length; i++) {// put all the element in the hashset...........
            mp.add(arr[i]);
        }
        int elem = 0;
        int count;
        int max = 0;
        for (int i = 0; i < arr.length; i++) {
            count = 1;
            elem = arr[i];// if it contains the element which is consecutively less than it means
                          // -1....then it is not the starting point of the consecutive subarray....
            if (!mp.contains(elem - 1)) {// if it doesn't contains the element means it is the starting point int the
                                         // subarray......
                while (mp.contains(elem + 1)) {// we will check that how long it contains the consecutive increasing
                                               // element.......
                    elem = elem + 1;
                    count++;// we will count the size....
                }
            }
            if (count > max)// we will calculate the max size.................
                max = count;
        }
        return max;

    }

    public static void main(String[] args) {
        int[] arr = { 100, 4, 200, 1, 1, 1, 3, 2 };
        int ans = FindLonconsc(arr);
        System.out.println("The largest consecutive subarray is : " + ans);
    }
}