import java.util.*;

public class ItineraryFromTIcket {
    public static void findTicketRoots(HashMap<String, String> mp) {
        String airport = "";
        for (String k : mp.keySet()) {// find the first airport......
            if (!mp.containsValue(k)) {
                System.out.print(k + " ");
                airport = mp.get(k);
                break;
            }
        }
        while (mp.containsKey(airport)) {// if contains the given airport as key then print it and make it's value as
                                         // new airport.......
            System.out.print(airport + " ");
            airport = mp.get(airport);
        }
        System.out.print(airport);// print the last airport.........
    }

    public static void main(String[] args) {
        HashMap<String, String> mp = new HashMap<>();
        mp.put("mumbai", "delhi");
        mp.put("chennai", "bangaluru");
        mp.put("goa", "chennai");
        mp.put("delhi", "goa");
        findTicketRoots(mp);
    }
}