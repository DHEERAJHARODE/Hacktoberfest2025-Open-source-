import java.util.Scanner;
public class FindMinAndMaxFromArray {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter  the size of Array : ");
        int size = sc.nextInt();
        int[] array = new int[size];
        System.out.println("Enter the "+size+" elements of Array : ");
        for (int i = 0; i<size; i++){
            array[i] = sc.nextInt();
        }
        int min = array[0];
        int max = array[0];
        for (int i = 1; i<size; i++){
            if (array[i] > max){
                max = array[i];
            }
            if (array[i] < min){
                min = array[i];
            }
        }
        System.out.println("Min value in array is : "+min);
        System.out.println("Max value in array is : "+max);
        sc.close();
    }
}