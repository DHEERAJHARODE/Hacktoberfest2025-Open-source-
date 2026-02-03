package hacktoberfestcode;

import java.util.Scanner;

public class running_sum_in_array {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		System.out.print("Enter the length of array: ");
		int n = s.nextInt();
		int nums[] = new int[n];
		for(int i=0;i<n;i++) {
			nums[i]= s.nextInt();
		}
		
		int res[] = runningSum(nums);
		for(int i=0;i<n;i++) {
			System.out.print(res[i]+ " ");
		}
	}
	
	 public static int[] runningSum(int[] nums) {
	        int res[]= new int[nums.length];
	        res[0] = nums[0];
	        for(int i=1;i<nums.length;i++){
	            res[i]= nums[i]+res[i-1];
	        }
	        
	        return res;
	    }

}
