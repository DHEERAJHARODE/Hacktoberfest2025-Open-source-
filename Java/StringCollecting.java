package classwork;


import java.util.Arrays;
import java.util.Scanner;


public class StringCollecting {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of strings:");
        int numStrings = sc.nextInt();
        String[] values = new String[numStrings];

        for (int i = 0; i < values.length; i++) {
            System.out.println("Enter the string " + (i + 1) + ":");
            values[i] = sc.next();
        }
       System.out.println("Given data");
       System.out.println(Arrays.toString(values));
    }

}

