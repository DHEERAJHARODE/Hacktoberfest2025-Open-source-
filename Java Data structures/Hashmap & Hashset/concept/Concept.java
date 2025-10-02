import java.util.HashMap;

public class Concept {
    public static void hashConcept() {
        HashMap<String, Integer> mp = new HashMap<>();
        mp.put("Asam", 1);
        mp.put("delhi", 2);
        mp.put("rj", 3);
        mp.put("Mp", 4);
        mp.put("up", 100);
        mp.remove("rj");
        System.out.println(mp.values());
        System.out.println(mp.keySet());
        System.out.println(mp.entrySet());
        mp.putIfAbsent("kashmir", 6);
        System.out.println(mp.entrySet());
        System.out.println(mp.containsKey("rj"));
        System.out.println(mp.containsKey("Mp"));
        System.out.println(mp.containsValue(100));
        mp.put("delhi", 200);// updates...................
        System.out.println(mp.entrySet());
        for (var k : mp.keySet()) {
            if (mp.get(k) == 200)
                mp.remove(k);
        }
    }

    public static void main(String[] args) {
        hashConcept();
    }
}