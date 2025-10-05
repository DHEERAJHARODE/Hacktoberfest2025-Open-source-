/*Prob.1 Given the adjacency list and number of vertices and edges of a graph, the task is to represent the 
adjacency list for a directed graph. 
input: V = 3, edges[][]= {{0, 1}, {1, 2} {2, 0}} 
Output:  
0 -> 1 
1 -> 2 
2 -> 0 
 
input: V = 4, edges[][] = {{0, 1}, {1, 2}, {1, 3}, {2, 3}, {3, 0}} 
Output: 
0 -> 1 
1 -> 2 3 
2 -> 3 
3 -> 0
 */
import java.util.*;
public class Problem1 {
    public static void main(String[] args) {
        int v = 3;
        int  edges[][] = {
            {0, 1},
            {1, 2},
            {2, 0}
        };

        // int v = 4;
        // int  edges[][] = {
        //     {0, 1},
        //     {1, 2},
        //     {1, 3},
        //     {2, 3},
        //     {3, 0}
        // };

        // HashMap<Integer,ArrayList<Integer>> map = new HashMap<>();
        // for(int i=0;i<edges.length;i++){
        //     map.putIfAbsent(edges[i][0], new ArrayList<>());
        //     map.get(edges[i][0]).add(edges[i][1]);
        // }
        
        // //System.out.println(map);
        // for (Map.Entry<Integer, ArrayList<Integer>> entry : map.entrySet()) {
        //     Integer key = entry.getKey();
        //     ArrayList<Integer> valueList = entry.getValue();

        //     System.out.print(key + " -> ");
        //     for (Integer val : valueList) {
        //         System.out.print(val + " ");
        //     }
        //     System.out.println();
        // }
        
        for(int i=0 ; i< edges.length; i++){
            String str = "";
            for(int j=0 ;j < edges.length ; j++){
                if(i == edges[j][0]){
                    str += (edges[j][1]) + " ";
                }
            }
            if(str.length() > 0){
                System.out.println(i + "->" + str);
            }
        }
    }
}