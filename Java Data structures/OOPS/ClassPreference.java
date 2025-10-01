import java.util.*;

class Sample {
    // public void Method(StringBuilder s) {
    // System.out.println("This is StringBuilder version");
    // }

    public void Method(String s) {
        System.out.println("This is String version");
    }

    public void Method(Object o) {
        System.out.println("This is Object version");
    }
}

public class ClassPreference {
    public static void main(String[] args) {
        Sample s1 = new Sample();
        String s = "vansh";
        s1.Method("vansh");// String version.....
        s1.Method(null);// first preference to child class(String) rather than parent
                        // (object).........if there is only one child class
                        // argument method is available......
        // s1.Method(null);// compilation error if there are more than one child class
        // argument method is
        // available........
    }
}
