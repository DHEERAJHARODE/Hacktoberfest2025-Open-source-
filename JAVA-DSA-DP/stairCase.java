import java.util.Scanner;

public class stairCase {

    public static long staircase(int n) {
        // Your code goes here

        if (n == 0 || n == 1)
            return 1;
        if (n == 2)
            return 2;

        long[] ways = new long[n + 1];

        ways[0] = 1;
        ways[1] = 1;
        ways[2] = 2;

        for (int i = 3; i <= n; i++) {

            ways[i] = ways[i - 1] + ways[i - 2] + ways[i - 3];
        }

        return ways[n];

    }

    public static void main(String[] args) {
        // TODO Auto-generated method stub

        Scanner sc = new Scanner(System.in);

        int num = sc.nextInt();

        long totalWays = staircase(num);
        System.out.println(totalWays);
    }

}
