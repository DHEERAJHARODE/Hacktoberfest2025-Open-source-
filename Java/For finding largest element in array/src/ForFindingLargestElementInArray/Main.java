package ForFindingLargestElementInArray;
import java.util.Scanner;
public class Main {

    public static void main(String[] args) {
        double[] list={5,3,2,8,6};
        double max=list[0];
        for (int i=0;i<list.length;i++)
        {
            if(list[i]>max)
            {
                max=list[i];
            }
        }
        System.out.println(max);
    }
}
