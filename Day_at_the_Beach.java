package Lec60;

// https://codeforces.com/problemset/problem/599/C

import java.util.Scanner;

public class Day_at_the_Beach {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        int[] leftmax = new int[n+1];
        leftmax[0] = Integer.MIN_VALUE;
        for (int i = 0; i < n; i++) {
            leftmax[i+1] = Math.max(leftmax[i], arr[i]);
        }

        int[] rightmin = new int[n+1];
        rightmin[n] = Integer.MAX_VALUE;
        for(int i=n-1; i>=0; i--){
            rightmin[i] = Math.min(rightmin[i+1], arr[i]);
        }

        int partition = 1;
        for (int i = 1; i < n; i++) {
            if(leftmax[i] <= rightmin[i]){
                partition++;
            }
        }

        System.out.println(partition);
    }
}
