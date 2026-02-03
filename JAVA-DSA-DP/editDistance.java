
public class editDistance {

    public static int editDistance(String s, String t) {
        // Your code goes here

        int m = s.length();
        int n = t.length();

        if (m == 0)
            return n;
        if (n == 0)
            return m;

        int myAns;

        if (s.charAt(0) == t.charAt(0)) {
            myAns = editDistance(s.substring(1), t.substring(1));

        } else {

            // replace first Character
            int ans1 = 1 + editDistance(s.substring(1), t.substring(1));

            // delete a character from string 1
            int ans2 = 1 + editDistance(s.substring(1), t.substring(0));

            // delete a character from string 2
            int ans3 = 1 + editDistance(s.substring(0), t.substring(1));

            myAns = Math.min(ans1, Math.min(ans2, ans3));
        }

        return myAns;

    }

    public static int editDistanceI(String s, String t) {
        // Your code goes here

        // Find the lengths of both strings
        int m = s.length();
        int n = t.length();

        int[][] dp = new int[m + 1][n + 1];

        // Initializing dp for iterative approach

        // column filling
        for (int i = n; i >= 0; i--)
            dp[m][i] = n - i;

        // row filling
        for (int i = m; i >= 0; i--)
            dp[i][n] = m - i;

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {

                if (s.charAt(i) == t.charAt(j)) {

                    dp[i][j] = dp[i + 1][j + 1];
                } else {

                    int ans1 = 1 + dp[i + 1][j + 1];
                    int ans2 = 1 + dp[i][j + 1];
                    int ans3 = 1 + dp[i + 1][j];

                    dp[i][j] = Math.min(ans1, Math.min(ans2, ans3));
                }
            }
        }
        return dp[0][0];

    }

}
