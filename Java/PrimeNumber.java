public class PrimeNumber{

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int numc = sc.nextInt();
        for (int j = 0; j < numc; j++) {

            int x = sc.nextInt();
            boolean ehprimo = false;
            for (int i = 2; i < x; i++) {
                if (x % i == 0) {
                    ehprimo = true;
                    break;
                }
            }
            if (ehprimo == false)
                System.out.println(x + " eh primo");

            else {
                System.out.println(x + " nao eh primo");
            }
        }
    }
}