public class TryCatchArithmatic {
    public static void main(String[] args) {
        System.out.println("This is example of try catch block : ");
        try {
            int x = 4 / 0;
        } catch (ArithmeticException e) {
            System.out.println("Hey this is an arithmetic exception");
        }
    }
}