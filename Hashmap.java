import java.util.*;
public class Main {
    public static void main(String[] args) {
        HashMap<Integer,String> map= new HashMap<Integer,String>();
        map.put(1,"Anurag");
        map.put(2,"****");

        for(Map.Entry m : map.entrySet()){
            System.out.println(m.getKey()+":"+m.getValue());
        }
        System.out.println(map);
        System.out.println(map.get(2));
        System.out.println(map.size());
        map.replace(2,"****");
        System.out.println(map);
        System.out.println(map.containsValue("Anurag"));
        map.put(3,"**");
        System.out.println(map.get(3));
        map.remove(3);
        System.out.println(map);
    }
}
