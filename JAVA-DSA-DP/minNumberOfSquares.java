import java.util.Scanner;

public class minNumberOfSquares {

    // simple recursive solution

    public static int minCount(int n) {
        // Your code goes here

        // base case
        if (n == 0)
            return 0;

        int minAns = Integer.MAX_VALUE;

        // explore all the possible paths
        for (int i = 1; i * i <= n; i++) {

            int currAns = minCount(n - (i * i));

            if (minAns > currAns) {
                minAns = currAns;
            }
        }

        int myAns = minAns + 1;
        return myAns;
    }

    // recursive dp solution

    public static int minCountRDp(int n, int[] dp) {
        // Your code goes here

        // base case
        if (n == 0)
            return 0;

        int minAns = Integer.MAX_VALUE;

        // explore all the possible paths
        for (int i = 1; i * i <= n; i++) {

            int currAns;
            if (dp[n - (i * i)] == -1) {
                currAns = minCount(n - (i * i));
                dp[n - (i * i)] = currAns;
            } else {
                currAns = dp[n - (i * i)];
            }

            if (minAns > currAns) {
                minAns = currAns;
            }
        }

        int myAns = minAns + 1;
        return myAns;
    }

    // Iterative dp solution

    public static int minCountIDp(int n) {
        // Your code goes here

        int dp[] = new int[n + 1];
        dp[0] = 0;

        for (int i = 1; i <= n; i++) {

            int minAns = Integer.MAX_VALUE;
            for (int j = 1; j * j <= i; j++) {

                int currAns = dp[i - (j * j)];

                if (minAns > currAns) {
                    minAns = currAns;
                }
            }

            dp[i] = 1 + minAns;
        }

        return dp[n];
    }

    public static void main(String[] args) {
        // TODO Auto-generated method stub

        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        // for recursive dp use , initialize the dp array
        int dp[] = new int[n + 1];
        for (int i = 0; i < dp.length; i++) {
            dp[i] = -1;
        }

        // int ans = minCountRDp(n, dp);

        int ans = minCountIDp(n);
        System.out.println(ans);
    }

}
