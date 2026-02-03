import java.util.*;
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
      if(ans==temp)
        return true;
      return false;
    }
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        while(true){
            System.out.println("Enter a number : ");
            String N=sc.nextLine();
            if(N.equals(""))
                break;
            System.out.println(N+" is a Palindrome no. : "+isPalindrome(Integer.parseInt(N)));
        }
    }
}
