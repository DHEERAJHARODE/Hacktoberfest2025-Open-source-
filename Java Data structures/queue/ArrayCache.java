package queue;

/**
 *
 * @author Sheetal Neeraj
 */
public class ArrayCache implements Queue {

    private int size;
    private Object[] array;
    private int capacity;

    public ArrayCache(int capacity) {
        array = new Object[capacity];
        this.capacity = capacity;
    }

    @Override
    public Object first() {
        if (this.isEmpty()) {
            throw new IllegalStateException("Cache is empty!");
        }
        return array[0]; // Return the least recently added item
    }

    @Override
    public Object remove() {
        if (this.isEmpty()) {
            throw new IllegalStateException("Cache is empty!");
        }
        Object obj = array[0];
        System.arraycopy(array, 1, array, 0, size - 1); // Shift elements left to evict the oldest
        array[--size] = null; // Reduce size
        return obj;
    }

    @Override
    public void add(Object obj) {
        if (size == this.capacity) {
            // Cache is full, evict the oldest item
            System.arraycopy(array, 1, array, 0, size - 1); // Shift elements left
            array[--size] = null;
        }
        array[size++] = obj; // Add new item to the cache
    }

    @Override
    public int size() {
        return size;
    }

    @Override
    public boolean isEmpty() {
        return size == 0;
    }

    public static void main(String[] args) {
        ArrayCache cache = new ArrayCache(3); // Cache with a capacity of 3
        cache.add(10);
        cache.add(20);
        cache.add(30);

        // Cache is full, next add will evict the oldest item (10)
        cache.add(40);

        // Display the first and last elements in the cache
        System.out.println("First item (least recently added): " + cache.first());
        System.out.println("Evicting first item: " + cache.remove());

        // After eviction, the current state of the cache
        System.out.println("First item after eviction: " + cache.first());
        System.out.println("Cache size: " + cache.size());
    }
}
