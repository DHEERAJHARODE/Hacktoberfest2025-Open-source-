import java.util.LinkedList;

public class linklist_inbuild {
    public static void printList(LinkedList list){
        for(int i=0;i<list.size();i++){
            System.out.print(list.get(i) + " -> ");
        }
        System.out.println("NULL");
        System.out.println();
    }
    public static void main(String[] args) {
        LinkedList<String> list = new LinkedList<>();
        list.addFirst("is");
        list.addFirst("this");
        list.addLast("a");
        list.add("list");           //add at last
        System.out.println(list);
        printList(list);
        System.out.println(list.size());
        
        list.remove();          //emove from front
        list.remove(1);         //remove from given index
        printList(list); 

        list.removeFirst();
        printList(list);

        list.removeLast();
        printList(list);

        System.out.println(list);
        System.out.println(list.size());


    }
}
