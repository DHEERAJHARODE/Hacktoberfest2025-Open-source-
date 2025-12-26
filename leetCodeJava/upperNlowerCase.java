import java.util.Scanner;
public class upperNlowerCase {
	public static String LowerCase(String s) {
        
         StringBuffer sb = new StringBuffer(s);
        for(int i=0;i<s.length();i++)
        {
            char c = s.charAt(i);
            if(Character.isUpperCase(c))
            {
            	c = (char) ((int)c + 32);
                sb.setCharAt(i, c);
            }
            else if(c == ' ')
            {
                sb.setCharAt(i, c);
            }
            else{
            	c = (char) ((int)c - 32);
                sb.setCharAt(i, c);
            }
        }
        String str = sb.toString();
        return str;
    }
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        sc.close();
        // String s = "Akarshan Sonkar";
        System.out.println(LowerCase(s));
    }
}
