/*
 The Moore Voting Algorithm is an efficient algorithm that finds the majority element in an array (an element that appears more than n/2 times) 
 The Moore's Voting Algorithm is an efficient algorithm that finds the majority element in an array (an element that appears more than n/2 times) 
 with O(n) time complexity and O(1) space complexity.
 */
public class MooreVotingAlgorithm {
    public static int majorityElement(int arr[]){
        int c=0;
        int n=arr.length;
        int ele=0;
        for(int i=0;i<n;i++){
            if(c==0){
                c=1;
                ele=arr[i];
            }
            else if(ele==arr[i]){
                c++;
            }
            else{
                c--;
            }
        }

        int c1=0;
        for(int i=0;i<n;i++){
            if(arr[i]==ele){
                c1++;
            }
        }
        if(c1>n/2){
            return ele;
        }
        return -1;

    }
    public static void main(String args[]){
     int arr[]={1,1,2,5,2,2,2,2};
     int ans=majorityElement(arr);
     System.out.println("Majority Element in the array with occurance more than n/2 times : "+ans);
    }
}