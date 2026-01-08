import java.util.*;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
public class TreeMaps {
    public static void main(String[] args) {
        String input = "";
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        try{
            input = br.readLine();
        }catch(IOException e){
            System.out.println(e.getMessage());
        }

        TreeMap<Character, Integer> tm = new TreeMap<>();
        for(char c: input.toCharArray()){
            if(tm.get(c)==null){
                tm.put(c,1);
            }else{
                tm.put(c,tm.get(c)+1);
            }
        }
        
        for(Map.Entry<Character,Integer> e: tm.entrySet()){
            System.out.println(e.getKey()+" : "+e.getValue());
        }
    }
}
