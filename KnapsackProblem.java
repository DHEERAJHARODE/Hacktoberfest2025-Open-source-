// KnapsackProblem.java
// Author: Your Name
// Description: 0/1 Knapsack Problem implementation in Java
// Intuition:
// The 0/1 Knapsack problem is a classic dynamic programming problem.
// Given n items with weights and values, and a knapsack of capacity W,
// the goal is to maximize the total value in the knapsack without exceeding its capacity.
//
// Approach:
// 1. We use a DP array dp[i][w] which represents maximum value for first i items and capacity w.
// 2. For each item, we have two choices:
//    a) Include the item (if it fits), then add its value and reduce capacity.
//    b) Exclude the item, keep previous value.
// 3. Take the max of including or excluding the item.
// 4. Return dp[n][W] as the answer.

import java.util.Scanner;

public class KnapsackProblem {

    // Function to solve 0/1 Knapsack problem using dynamic programming
    public static int knapsack(int[] values, int[] weights, int n, int W) {
        int[][] dp = new int[n + 1][W + 1];

        // Build table dp[][] in bottom-up manner
        for (int i = 0; i <= n; i++) {
            for (int w = 0; w <= W; w++) {
                if (i == 0 || w == 0) {
                    dp[i][w] = 0; // Base case: 0 items or 0 capacity
                } else if (weights[i - 1] <= w) {
                    // Option 1: include the item
                    int include = values[i - 1] + dp[i - 1][w - weights[i - 1]];
                    // Option 2: exclude the item
                    int exclude = dp[i - 1][w];
                    dp[i][w] = Math.max(include, exclude);
                } else {
                    dp[i][w] = dp[i - 1][w]; // Cannot include item
                }
            }
        }
        return dp[n][W]; // Maximum value achievable
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of items: ");
        int n = sc.nextInt();

        int[] values = new int[n];
        int[] weights = new int[n];

        System.out.println("Enter values of items:");
        for (int i = 0; i < n; i++) {
            values[i] = sc.nextInt();
        }

        System.out.println("Enter weights of items:");
        for (int i = 0; i < n; i++) {
            weights[i] = sc.nextInt();
        }

        System.out.print("Enter maximum capacity of knapsack: ");
        int W = sc.nextInt();

        int maxValue = knapsack(values, weights, n, W);
        System.out.println("Maximum value in knapsack = " + maxValue);

        sc.close();
    }
}

/*
Sample Input:
Enter number of items: 3
Enter values of items:
60 100 120
Enter weights of items:
10 20 30
Enter maximum capacity of knapsack: 50

Sample Output:
Maximum value in knapsack = 220
*/
