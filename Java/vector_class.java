import java.util.Vector;

public class vector_class {

    public static void main(String[] args) {

        Vector<String> vect1 = new Vector<>();           // for create vector class
        vect1.add("A");                               // for adding elements in vector
        vect1.add("B");
        vect1.add(0, "C");               // adding element at particular index
        System.out.println("Vect 1: " + vect1);

        Vector<String> vect2 = new Vector<>();
        vect2.addAll(vect1);
        System.out.println("Vect 2: " + vect2);
        System.out.println("Element value: " + vect1.get(2));
        vect1.remove(1);                         // removing element from vector
        System.out.println("After removal Vect 1: " + vect1);
        vect2.clear();                                  // for clear any vector
        System.out.println("After clear Vect 2: " + vect2);
        System.out.println("Vect 2 size: " + vect2.size()); // printing vector size
    }
}
