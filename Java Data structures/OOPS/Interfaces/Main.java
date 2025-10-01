public class Main {
    static class cl implements B {

        @Override
        public void show() {
            System.out.println("Hey man this is show method which is overridden in the cl class...........");
        }

        @Override
        public void sayHi() {
            System.out.println("HI.........................");
        }

        @Override
        public void sayBi() {
            System.out.println("Biyyyyyyyyyyyyyyyyy..............");
        }

    }

    public static void main(String[] args) {
        cl c = new cl();
        c.sayBi();
        c.sayHi();
        System.out.println("This is interface data member : " + B.n);// accessing the n variable through interface
                                                                     // name........because it is static
        // and final by default so it cannot be accessed through obj........
    }
}
