class Parent {
    protected void method() {// private function do not participate in overrinding.......
        System.out.println("This is parent's method");
    }
}

class Child extends Parent {
    @Override // it is not neccessay to write this annotation, but it's a good practice
              // because
              // it makes the code more readable.......
    public void method() {
        System.out.println("This is child's method");
    }

    public void GetParentMethod() {// helper function..............
        super.method();// if we want to access the method of parent class through child class then we
                       // need to use "super" keyword......
    }
}// if we want to access anything of parent class through child class then we
 // will use the "super" keyword.............

public class Overriding {
    public static void main(String[] args) {
        Parent p = new Parent();
        p.method();
        Child c = new Child();
        c.method();
        Parent p1 = new Child();// method will be called based on the runtime object not on the
                                // reference.........
                                // this is also called virtual function......
        p1.method();
        c.GetParentMethod();// this is how we can access the parent class method using child
                            // class...........
    }
}
