import java.util.*;
public class Maps{
    public static void main(String args[]){
        Scanner s = new Scanner(System.in);
        String input = s.nextLine();
        HashMap<Character, Integer> hm = new HashMap<>();
        for(char c: input.toCharArray()){
            if(hm.containsKey(c)){
                hm.replace(c, hm.get(c) +1);
            }else{
                hm.put(c,1);
            }
        }
        for(Map.Entry<Character, Integer> e: hm.entrySet()){
            System.out.println(e.getKey()+" : "+e.getValue());
        }
        s.close();
    }
}