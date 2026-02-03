public class BubbleSort {
    public static void bubbleSort (int input[]){
        
        for (int i=0; i < input.length - 1; i++){
            
            // more optimized for loop is :
//            for (int j =0; j < input.length - i -1; j++)
            for (int j=0; j < input.length - 1; j++){

                if (input[j] > input[j+1]) {
                    int temp = input[j];
                    input[j] = input[j + 1];
                    input[j + 1] = temp;
                }
            }
        }

    }
    public static void main(String[] args) {

        int input[] = {8,2,6,1,5};
        bubbleSort(input);

        // this loop is for printing the elements
        for (int i = 0; i < input.length; i++){
            System.out.print(input[i] + " ");
        }
    }

}
