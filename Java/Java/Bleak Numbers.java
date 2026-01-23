/*
Bleak Numbers
Given an integer, check whether it is Bleak or not.
A number n is called Bleak if it cannot be represented as sum of a positive number x and set bit count in x, i.e., x + countSetBits(x) is not equal to n for any non-negative number x.
Example 1:
Input: 
4
Output: 
1
Explanation: 
There is no x such that x + countSetbit(x) = 4
Example 2:
Input: 
3
Output: 
0
Explanation: 
3 is a Bleak number as 2 + countSetBit(2) = 3.
*/

import java.util.*;
import java.lang.*;
import java.io.*;
class GFG
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine().trim());
        while(T-->0)
        {
            int n = Integer.parseInt(br.readLine().trim());
            Solution ob = new Solution();
            int ans = ob.is_bleak(n);
            System.out.println(ans);
        }
    }
}

// } Driver Code Ends


//User function Template for Java

class Solution
{
    public int is_bleak(int n)
    {
        // Code here
        int m = n;
        int x = 0;
        while(n>0){
            n=n/2;
            x++;
        }

        for(int i=m-1; i>=m-x; i--){
            if(i+countSetBits(i)==m) return 0;
        }

        return 1;
    }
    int countSetBits(int x){
        int ans = 0;
        while(x>0){
            if((x&1)==1) ans++;
            x=x>>1;
        }
        return ans;
    }
}
