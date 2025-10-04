import java.util.*;

public class RomanNumeralConverter {

    private static final TreeMap<Integer, String> map = new TreeMap<>();

    static {
        map.put(1000, "M");
        map.put(900, "CM");
        map.put(500, "D");
        map.put(400, "CD");
        map.put(100, "C");
        map.put(90, "XC");
        map.put(50, "L");
        map.put(40, "XL");
        map.put(10, "X");
        map.put(9, "IX");
        map.put(5, "V");
        map.put(4, "IV");
        map.put(1, "I");
    }

    public static String toRoman(int number) {
        int l = map.floorKey(number);
        if (number == l) {
            return map.get(number);
        }
        return map.get(l) + toRoman(number - l);
    }

    public static int fromRoman(String roman) {
        Map<Character, Integer> values = new HashMap<>();
        values.put('I', 1);
        values.put('V', 5);
        values.put('X', 10);
        values.put('L', 50);
        values.put('C', 100);
        values.put('D', 500);
        values.put('M', 1000);

        int result = 0;
        for (int i = 0; i < roman.length(); i++) {
            int value = values.get(roman.charAt(i));
            if (i + 1 < roman.length() && value < values.get(roman.charAt(i + 1))) {
                result -= value;
            } else {
                result += value;
            }
        }
        return result;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Choose option: \n1. Integer to Roman \n2. Roman to Integer");
        int choice = sc.nextInt();
        sc.nextLine();

        if (choice == 1) {
            System.out.print("Enter an integer: ");
            int num = sc.nextInt();
            System.out.println("Roman numeral: " + toRoman(num));
        } else if (choice == 2) {
            System.out.print("Enter a Roman numeral: ");
            String roman = sc.nextLine().toUpperCase();
            System.out.println("Integer value: " + fromRoman(roman));
        } else {
            System.out.println("Invalid choice!");
        }
    }
}
