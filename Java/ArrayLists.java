import java.util.*;
public class ArrayLists {
    public static void main(String args[]){
        ArrayList<Integer> al = new ArrayList<Integer>();
        al.add(1);
        al.add(2);
        al.addFirst(10);
        al.addLast(30);

        ArrayList<Integer> a2 = new ArrayList<>();
        a2.addAll(al);
        a2.add(40);

        for(int i: a2){
            System.out.println(i);
        }

        System.out.println("Using Iterator");

        Iterator<Integer> i = al.iterator();

        while(i.hasNext()){
            System.out.println(i.next());
        }
    }    
}
