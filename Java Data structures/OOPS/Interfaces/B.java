public interface B extends A {
    int n = 123;// by default the the variables defined inside the interface are public static
                // and final by default.................

    void sayHi();

    void sayBi();
}
