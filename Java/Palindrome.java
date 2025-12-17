import java.util.Scanner;

public class Palindrome {
    public static boolean isPalindrome(int n) {
      int temp = n;
      int rem;
      int ans = 0;
      while(n>0){
        rem = n%10;
        ans = ans*10+rem;
        n=n/10;
      }
      if(ans==temp){
        return true;
      }
      return false;
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        boolean res = isPalindrome(N);
        System.out.print(res);
        sc.close();
    }
}
