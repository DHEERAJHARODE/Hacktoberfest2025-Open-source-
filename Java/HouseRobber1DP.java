// Problem: House RobberI (Dynamic Programming)
// Author: Mandira Singh
// Date: 13 October 2025
// Description: Find maximum sum of non-adjacent houses.

public class HouseRobber1DP {
    static int houseRob(int []nums){
        int n = nums.length;
        if(n <= 1){   //base condition
            return nums[0];
        }
        int[]t = new int[n + 1];
        t[0] = 0;
        t[1] = nums[0];
        for(int i = 2; i < n - 1; i++){
            int skip = t[i - 1];
            int steal = nums[i  - 1] + t[i - 2];
            t[i] = Math.max(skip, steal);
        }
        return t[n - 1];
    }
}
