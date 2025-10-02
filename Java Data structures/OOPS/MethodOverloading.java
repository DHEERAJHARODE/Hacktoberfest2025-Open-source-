class Overloaded {// this method gives deeper understanding that how compiler binds the method
                  // body at the compile time.....
    public void add(int a, float b) {
        System.out.println("Adding int and float");
    }

    public void add(float a, int b) {
        System.out.println("Adding float and int");
    }

    public void add(float a, float b) {
        System.out.println("Adding float and float");
    }
}

public class MethodOverloading {
    public static void main(String[] args) {
        Overloaded o1 = new Overloaded();
        // o1.add(0, 0);// compile time error because compiler is confused that which
        // method to
        // call..........
        o1.add(0.3f, 3);
        o1.add(0, 0.1f);
        o1.add(0.1f, 0.1f);
        // o1.add(3, 4);// compiler will be confused.....ambigious problem......
    }
}