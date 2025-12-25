import java.util.Scanner;

public class triangle {
    public static void main(String[] args) {
        int sisi1, sisi2, sisi3;
        Scanner input = new Scanner(System.in);

        System.out.print("Masukkan sisi pertama\t: ");
        sisi1 = input.nextInt();
        System.out.print("Masukkan sisi kedua\t: ");
        sisi2 = input.nextInt();
        System.out.print("Masukkan sisi ketiga\t: ");
        sisi3 = input.nextInt();

        if (sisi1 == sisi2 && sisi2 == sisi3 ) {
            System.out.println("Segitiga sama sisi");
        } else if (sisi1 == sisi2 || sisi2 == sisi3 || sisi1 == sisi3) {
            System.out.println("Segitiga sama kaki");
        } else {
            System.out.println("Segitiga sembarang");
        }
    }
}
