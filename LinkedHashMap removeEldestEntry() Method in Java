// Java program to illustrate removeEldestEntry()
import java.util.*;

public class Linked_Hash_Map_Demo {

	// Refers to the max size of the map following which
	// the removal takes place of the eldest entry
	private static final int MAX = 6;

	public static void main(String[] args)
	{

		// Creating the linked hashmap and implementing
		// removeEldestEntry() to MAX size
		LinkedHashMap<Integer, String> li_hash_map = 
		new LinkedHashMap<Integer, String>() {
			protected boolean removeEldestEntry(Map.Entry<Integer, String> eldest)
			{
				return size() > MAX;
			}
		};
		// Adding elements using put()
		li_hash_map.put(0, "Welcome");
		li_hash_map.put(1, "To");
		li_hash_map.put(2, "The");
		li_hash_map.put(3, "World");
		li_hash_map.put(4, "Of");
		li_hash_map.put(5, "geeks");

		System.out.println("" + li_hash_map);

		// Adding more elements
		li_hash_map.put(6, "GeeksforGeeks");

		// Displaying the map after adding one more element
		System.out.println("" + li_hash_map);

		// Adding more elements
		li_hash_map.put(7, "Hello");

		// Displaying the map after adding one more element
		System.out.println("" + li_hash_map);
	}
}
