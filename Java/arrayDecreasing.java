import java.util.*;;

public class arrayDecreasing {

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int a = s.nextInt();
        int b = s.nextInt();
        int c = s.nextInt();

        if (a < b) {
            if (b < c) {
                if (a > c) {
                    int temp = c;
                    c = b;
                    b = temp;
                    System.out.println("the decreasing order is:" + a + b + c);
                } else {
                    int temp = c;
                    c = a;
                    a = temp;
                    System.out.println("the decreasing order is:" + a + b + c);
                }
            } else {

                if (a > c) {
                    int temp = b;
                    b = a;
                    a = temp;
                    System.out.println("the decreasing order is:" + a + b + c);
                } else {
                    int temp = b;
                    b = c;
                    c = temp;
                    System.out.println("the decreasing order is:" + a + b + c);
                }

            }
        } else {
            if(b>c)
            {
                if(a>c)
                {
                    System.out.println("the decreasing order is:" + a + b + c);
                }
                else
                {
                    int temp = c;
                    c = a;
                    a = temp;
                    System.out.println("the decreasing order is:" + a + b + c);
                }

            }
            else
            {
                if(a>c)
                {
                    int temp = b;
                    b = c;
                    c = temp;
                    System.out.println("the decreasing order is:" + a + b + c);

                }
                else{
                    int temp1=a;
                    int temp2=b;
                    a=c;
                    b=temp1;
                    c=temp2;
                    System.out.println("the decreasing order is:" + a + b + c);
                }
            }
        }

        s.close();

    }
}
