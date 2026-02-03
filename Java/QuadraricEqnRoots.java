
import java.util.Scanner;

public class QuadraricEqnRoots {
    public static void main(String[] args) {

                Scanner obj =new Scanner(System.in);
                System.out.println("Enter the coefficients of Eqn aX^2+bX+c\n");
                double a = obj.nextDouble();
                double b = obj.nextDouble();
                double c = obj.nextDouble();

                double root1, root2;


                double D = b * b - 4 * a * c;


                if (D > 0) {
                    root1 = (-b + Math.sqrt(D)) / (2 * a);
                    root2 = (-b - Math.sqrt(D)) / (2 * a);
                    System.out.format("root1 = %.2f and root2 = %.2f", root1, root2);
                }
                else if (D == 0) {
                    root1 = root2 = -b / (2 * a);
                    System.out.format("root1 = root2 = %.2f;", root1);
                }
                else {
                    double real = -b / (2 * a);
                    double imaginary = Math.sqrt(-D) / (2 * a);
                    System.out.format("root1 = %.2f+%.2fi", real, imaginary);
                    System.out.format("\nroot2 = %.2f-%.2fi", real, imaginary);
                }
            }
        }
