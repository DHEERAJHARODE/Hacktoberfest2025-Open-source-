import java.util.*;;
public class meter2Feet {
    
    public static void main(String[] args) {
        Scanner s= new Scanner(System.in);
        double m=s.nextDouble();
        System.out.println("the given measurment in meter is :"+m);
        double f=0;
        f= (m*3.28);
        System.out.println("the feet measurment is :"+f);
s.close();
    }
}
