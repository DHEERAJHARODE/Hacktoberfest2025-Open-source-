package function;
import java.util.Scanner;

public class Stalin_Sort {

    public static int[] arrInput(Scanner sc) {
        System.out.print("Enter the size of the array: ");
        int n = sc.nextInt();
        int[] arr = new int[n];
        System.out.println("Enter the elements of the array: ");
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        return arr;
    }

    public static int[] stalinSort(int[] arr) {
        // The list where we will store the "sorted" Stalinized elements
        int[] result = new int[arr.length];
        int index = 0;
        
        result[index++] = arr[0];  // The first element is always part of the sorted list

        for (int i = 1; i < arr.length; i++) {
            if (arr[i] >= result[index - 1]) {
                result[index++] = arr[i];
            }
        }

        // Truncate the array to only the valid elements
        int[] finalResult = new int[index];
        System.arraycopy(result, 0, finalResult, 0, index);
        
        return finalResult;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int[] arr = arrInput(sc);
        
        System.out.print("Array before Stalin sort: ");
        for (int num : arr) {
            System.out.print(num + " ");
        }
        System.out.println();
        
        // Apply Stalin sort
        int[] sortedArr = stalinSort(arr);
        
        System.out.print("Array after Stalin sort: ");
        for (int num : sortedArr) {
            System.out.print(num + " ");
        }
        System.out.println();
        
        sc.close();
    }
}
