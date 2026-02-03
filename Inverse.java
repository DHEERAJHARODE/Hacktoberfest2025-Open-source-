import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner scn = new Scanner(System.in);
    int n = scn.nextInt();

    int inverted = 0;
    int power = 1;

    while (n > 0) {
      int digit = n % 10;
      n = n / 10;
      inverted += power * Math.pow(10, digit - 1);
      power++;
    }
    System.out.println(inverted);
  }
}
