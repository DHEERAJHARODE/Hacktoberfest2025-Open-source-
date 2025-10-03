import java.util.Scanner;

public class CarNumberSunday {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt(); // number of cars
        sc.nextLine(); // consume newline

        for (int i = 0; i < N; i++) {
            String carNumber = sc.nextLine().trim();
            if (canRunOnSunday(carNumber)) {
                System.out.println("Yes");
            } else {
                System.out.println("No");
            }
        }
        sc.close();
    }

    // method to check rules
    private static boolean canRunOnSunday(String carNumber) {
        int sumEven = 0, sumOdd = 0;

        for (char ch : carNumber.toCharArray()) {
            if (Character.isDigit(ch)) {
                int digit = ch - '0';
                if (digit % 2 == 0) {
                    sumEven += digit;
                } else {
                    sumOdd += digit;
                }
            }
        }

        return (sumEven % 4 == 0) || (sumOdd % 3 == 0);
    }
}
