class Generics<E> {// Generic means a type of parameter, which can be used by classes ans methods
                   // to work on
                   // different data types.....it only accepts object type
                   // (Integer,Character,String
                   // etc).......
    private E data;// this is E type data..............

    public Generics(E data) {// Constructor..............
        this.data = data;
    }

    public E getData() {// Method which returns the E type of data........
        return data;
    }
}

public class Gen {
    static <T> void printData(T data) {// method using generic.................
        System.out.println(data);
    }

    public static void main(String[] args) {
        Generics<String> g1 = new Generics<>("Vansh");
        Generics<Integer> g2 = new Generics<>(32342);
        System.out.println("Hey man this is String data type of the generic : " + g1.getData());
        System.out.println("Hey man this is Integer data type of generic : " + g2.getData());
        printData(10325);
        printData("I'm printing the data through method using generic");
    }
}