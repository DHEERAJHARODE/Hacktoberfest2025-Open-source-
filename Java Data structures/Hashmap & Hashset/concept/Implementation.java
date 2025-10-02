import java.util.*;

public class Implementation {// Most important implementation...................................
    public static class MyHashMap<K, V> {
        static final int DEFAULT_SIZE = 4;// size of the table.............
        static final float LOAD_FACTOR = 0.75f;// load factor till which the elements can be entered............
        LinkedList<Node>[] table;
        int n = 0;// no. of entries................

        public class Node {// Node which contains key and value............
            K key;
            V value;

            Node(K key, V value) {
                this.key = key;
                this.value = value;
            }
        }

        private int Hashfunction(K key) {// converts the key into an random integer and gives its modulus with the size
                                         // of table i.e keycode%size.....
                                         // Note - Math.abs method is used cause random integer could be negative
                                         // also............
                                         // Note - hashcode() always generates same output of any particular
                                         // key..........
            int keycode = key.hashCode();
            return (Math.abs(keycode)) % DEFAULT_SIZE;
        }

        private void Makelist(int size) {// Used to create individual list for each index of table............
            table = new LinkedList[size];
            for (int i = 0; i < table.length; i++) {
                table[i] = new LinkedList<>();
            }
        }

        private void Rehashing() {
            LinkedList<Node>[] oldtable = table;
            Makelist(oldtable.length * 2);
            for (var ll : oldtable) {// copying the entries into new table............
                for (var node : ll) {
                    put(node.key, node.value);
                }
            }
        }

        public MyHashMap() {
            Makelist(DEFAULT_SIZE);
        }

        public int Size() {// returns size of the table..........
            return table.length;
        }

        private int traverse(LinkedList<Node> ll, K key) {// traverse the linkedlist and return the idx of the key if it
                                                          // is present else returns -1;
            for (int i = 0; i < ll.size(); i++) {
                if (ll.get(i).key == key) {
                    return i;
                }
            }
            return -1;
        }

        public void put(K key, V value) {// insert.................
            int tableidx = Hashfunction(key);
            LinkedList<Node> currll = table[tableidx];
            int trresult = traverse(currll, key);
            if ((n / table.length) > LOAD_FACTOR) {
                Rehashing();
            }
            if (trresult == -1) {// there is no existing element of the same key........then make new entry......
                Node node = new Node(key, value);
                currll.add(node);
                n++;
            } else {// else update the existing key's value.............
                currll.get(trresult).value = value;
            }
        }

        public V get(K key) {// get the particular value............
            int tableidx = Hashfunction(key);
            LinkedList<Node> currll = table[tableidx];
            int trresult = traverse(currll, key);
            if (trresult == -1) {
                return null;
            } else {
                return currll.get(trresult).value;
            }
        }

        public V remove(K key) {// remove the element.........................
            int tableidx = Hashfunction(key);
            LinkedList<Node> currll = table[tableidx];
            int trresult = traverse(currll, key);
            if (trresult == -1) {
                return null;
            } else {
                V val = currll.get(trresult).value;
                currll.remove(trresult);// remove the node of the given key.......
                n--;
                return val;
            }
        }

        public void Keyset() {
            System.out.print("[");
            for (var ll : table) {
                for (var node : ll) {
                    System.out.print(node.key + ", ");
                }
            }
            System.out.print("]");
            System.out.println();
        }

        public void values() {
            System.out.print("[");
            for (var ll : table) {
                for (var node : ll) {
                    System.out.print(node.value + ", ");
                }
            }
            System.out.print("]");
            System.out.println();
        }

        public boolean containskey(K key) {
            int tableidx = Hashfunction(key);
            LinkedList<Node> currll = table[tableidx];
            int trresult = traverse(currll, key);
            if (trresult == -1) {
                return false;
            }
            return true;
        }
    }

    public static void main(String[] args) {
        MyHashMap<String, Integer> mp = new MyHashMap<>();
        System.out.println(mp.remove("vansh"));
        System.out.println("Size is : " + mp.Size());
        mp.put("vansh", 1);
        mp.put("vinkesh", 500);
        System.out.println(mp.get("vinkesh"));
        System.out.println("Size is : " + mp.Size());
        mp.put("aniket", 3);
        System.out.println("Size is : " + mp.Size());
        mp.put("vikash", 5);
        System.out.println("Size is : " + mp.Size());
        mp.put("assam", 7);
        System.out.println("Size is : " + mp.Size());
        mp.put("maha", 6);
        System.out.println("Size is : " + mp.Size());
        mp.put("assam", 8);
        System.out.println("Size is : " + mp.Size());
        System.out.println(mp.containskey("vansh"));
        System.out.println(mp.containskey("vaibhavi"));
        mp.Keyset();
        mp.values();
    }
}
