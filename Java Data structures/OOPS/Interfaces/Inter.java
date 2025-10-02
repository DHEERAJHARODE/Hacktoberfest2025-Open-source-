public interface Inter {
    interface anotherInter {
        static void sayHello() {// since static methods cannot be inherited and overridden , (because overriding
                                // is runtime polymorphism, that's why it depends on object and static method
                                // does'nt depend on object they depend on class...) and belongs directly
                                // to the class
                                // rather than object so it must have body in interface...
            System.out.println("Hello.....");
        }

        void display();// by default methods are public, abstract.........
    }
}

class TestClass implements Inter.anotherInter {
    @Override
    public void display() {
        System.out.println("Hey this is display method........");
    }

    public static void main(String[] args) {
        TestClass t = new TestClass();
        Inter.anotherInter.sayHello();
        t.display();
    }
}
