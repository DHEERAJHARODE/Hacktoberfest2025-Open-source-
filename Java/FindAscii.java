public class FindAscii {

    public static void main(String[] args) {

        char chr = 'a';
        int ascii = chr;
        int castAscii = (int) chr;

        System.out.println("The ASCII " + chr + " is: " + ascii);
        System.out.println("The ASCII " + chr + " is: " + castAscii);
    }
}
