public interface A {// an interface must have its own file name...........
    void show();
}

class Vansh implements A {// implementing the A interface in vansh class...........
    public static void main(String[] args) {
        Vansh v = new Vansh();
        v.show();
    }

    @Override // we must implement all the methods of the
              // interface.............................
    public void show() {
        System.out.println("Hey interface method is overridden..........");
    }
}