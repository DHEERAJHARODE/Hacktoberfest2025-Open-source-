import java.util.*;;

public class calculateBmi {

    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);
        double w = s.nextDouble();
        System.out.println("the weight(pounds) is: " + w);
        double h = s.nextDouble();
        System.out.println("the height(inches) is: " + h);
        double bmi;
        bmi = (w*0.45359237)/((h*0.0254)*(h*0.0254));
        System.out.println("the bmi is: " + bmi);
        s.close();
    }
}
