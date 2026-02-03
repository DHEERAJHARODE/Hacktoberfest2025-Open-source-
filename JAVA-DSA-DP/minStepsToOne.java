import java.util.Scanner;

public class minStepsToOne {

    // SIMPLE RECURSION SOLUTION

    public static int countMinStepsToOne(int n) {
        // Your code goes here

        if (n == 1)
            return 0;

        int ans1, ans2 = Integer.MAX_VALUE, ans3 = Integer.MAX_VALUE;

        ans1 = countMinStepsToOne(n - 1);

        if (n % 2 == 0) {
            ans2 = countMinStepsToOne(n / 2);
        }

        if (n % 3 == 0) {
            ans3 = countMinStepsToOne(n / 3);
        }

        int myAns = Math.min(ans1, Math.min(ans2, ans3)) + 1;

        return myAns;

    }

    // RECURSIVE DP SOLUTION

    public static int countMinStepsToOneRDp(int n, int[] dp) {
        // Your code goes here

        if (n == 1)
            return 0;

        int ans1, ans2 = Integer.MAX_VALUE, ans3 = Integer.MAX_VALUE;

        if (dp[n - 1] == -1) {
            ans1 = countMinStepsToOneRDp(n - 1, dp);
            dp[n - 1] = ans1;
        } else {
            ans1 = dp[n - 1];
        }

        if (n % 2 == 0) {
            if (dp[n / 2] == -1) {
                ans2 = countMinStepsToOneRDp(n / 2, dp);
                dp[n - 2] = ans2;
            } else {
                ans2 = dp[n - 2];
            }
        }

        if (n % 3 == 0) {
            if (dp[n / 3] == -1) {
                ans3 = countMinStepsToOneRDp(n / 3, dp);
                dp[n - 3] = ans3;
            } else {
                ans3 = dp[n - 3];
            }
        }

        int myAns = Math.min(ans1, Math.min(ans2, ans3)) + 1;

        return myAns;

    }

    // ITERATIVE DP SOLUTION

    public static int countMinStepsToOneIDp(int n) {
        // Your code goes here

        if (n == 1)
            return 0;

        int[] dp = new int[n + 1];

        dp[1] = 0;

        for (int i = 2; i <= n; i++) {

            int ans1, ans2 = Integer.MAX_VALUE, ans3 = Integer.MAX_VALUE;

            ans1 = dp[i - 1];

            if (i % 2 == 0) {
                ans2 = dp[i / 2];
            }

            if (i % 3 == 0) {
                ans3 = dp[i / 3];
            }
            dp[i] = Math.min(ans1, Math.min(ans2, ans3)) + 1;

        }

        return dp[n];
    }

    // MAIN FUNCTION

    public static void main(String[] args) {
        // TODO Auto-generated method stub

        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();

        int[] dp = new int[num + 1];
        for (int i = 0; i < dp.length; i++) {
            dp[i] = -1;
        }

        int minSteps = countMinStepsToOneRDp(num, dp);
        System.out.println(minSteps);
    }

}
