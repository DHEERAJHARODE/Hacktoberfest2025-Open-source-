import java.util.ArrayList;
import java.util.Collections;

public class ArrayListReverseExample
 
{

    public static void main(String[] args)
 
{
        ArrayList<String> arrayList = new ArrayList<>();
        arrayList.add("Element 1");
        arrayList.add("Element 2");
        arrayList.add("Element 3");

        Collections.reverse(arrayList);

        System.out.println("Reversed List: " + arrayList);
    }
}
