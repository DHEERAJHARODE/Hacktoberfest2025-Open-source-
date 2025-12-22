import java.util.*;
public class solvePolynomial {
    

    public static void main(String[] args) {
        Scanner s=new Scanner(System.in);
        double a = s.nextDouble();
        System.out.println("the value of a:"+a);
        double b = s.nextDouble();
        System.out.println("the value of b:"+b);
        double c = s.nextDouble();
        System.out.println("the value of c:"+c);
        double d = s.nextDouble();
        System.out.println("the value of d:"+d);
        double e = s.nextDouble();
        System.out.println("the value of e:"+e);
        double f = s.nextDouble();
        System.out.println("the value of f:"+f);
        double x=0,y=0;
        // ax+by=e  cx+dy=f

        x=(e*d - b*f)/(a*d-b*c);
        y=(a*f-e*c)/(a*d-b*c);

        System.out.println("the value of x and y is :"+x+" and "+y);
s.close();
    }
}
