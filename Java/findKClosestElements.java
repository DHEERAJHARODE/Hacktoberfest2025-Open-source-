import java.util.*;
import java.io.*;;
class Solution {
    public List<Integer> findClosestElements(int[] arr, int k, int x) {
        int l = 0;
        int r = arr.length - 1;
        while(r-l >= k){
            if(Math.abs(arr[l]-x) > Math.abs(arr[r]-x)){
                l++;
            }
            else
                r--;
        }
		List<Integer> array = new ArrayList<Integer>();
		for (int i=l; i<=r; i++) {
			array.add(arr[i]);
		}
		return array;
    }
}
public class findkclosestelements {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int k= Integer.parseInt(br.readLine());
        int x= Integer.parseInt(br.readLine());
        Solution s = new Solution();
        int n= Integer.parseInt(br.readLine());
        int arr[]= new int[n];
        for(int i=0; i<n; i++){
            arr[i]= Integer.parseInt(br.readLine());
        }
        List<Integer> ss = s.findClosestElements(arr, k, x);
        System.out.println(ss);
    }
    
}
