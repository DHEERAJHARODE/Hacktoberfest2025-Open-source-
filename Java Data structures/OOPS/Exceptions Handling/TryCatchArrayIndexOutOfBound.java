public class TryCatchArrayIndexOutOfBound {
    public static void main(String[] args) {
        int[] arr = { 1, 2, 3 };
        try {
            System.out.println(arr[-1]);
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("This is an ArrayIndexOutOfBounds Exception");
        } // or
        try {
            System.out.println(arr[-1]);
        } catch (RuntimeException e) {// RuntimeException is parent class of ArrayIndexOutOfBoundsException
                                      // class................
            System.out.println("This is ArrayIndexOutOfBounds exception But paramerized as Runtime Exception");
        } // or
        try {
            System.out.println(arr[-1]);
        } catch (Exception e) {// Exception is parent class of RuntimeException class and grandParent of
                               // ArrayIndexOutOfBoundsException.......
            System.out.println("This is ArrayIndexOutOfBounds exception But paramerized as Exception");
        }
        // we can use either specific exception (Such as runtime , arrayindexoutofBounds
        // or whatever) in catch or direct use Exception (which is parent of all type of
        // exception) as a parameter according to our program's need........
    }
}
