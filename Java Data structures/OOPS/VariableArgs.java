class Variable {
    public void add(int... args) {// if we put 3 dots then we can take any number of input as
                                  // argument..............
        int sum = 0;
        for (int a : args) {
            sum += a;
        }
        System.out.println("The Sum is : " + sum);
    }
}

public class VariableArgs {
    public static void main(String[] args) {
        Variable v = new Variable();
        v.add(1, 2, 4, 5);
        v.add(1, 2);
        v.add(1);
        v.add();
    }
}
