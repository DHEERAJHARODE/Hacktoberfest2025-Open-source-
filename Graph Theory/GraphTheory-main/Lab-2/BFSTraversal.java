/*Prob. 2 Perform a Breadth First Search (BFS) traversal starting from vertex 0, visiting vertices from left to 
right according to the adjacency list, and return a list containing the BFS traversal of the graph.  
Input: adj[][] = [[1,2], [0,2,3], [0,1,4], [1,4], [2,3]] 
 
 
 
Output: [0, 1, 2, 3, 4] 
Explanation: Starting from 0, the BFS traversal will follow these steps:  
Visit 0 → Output: [0]  
Visit 1 (first neighbor of 0) → Output: [0, 1] 
Visit 2 (next neighbor of 0) → Output: [0, 1, 2] 
Visit 3 (next neighbor of 1) → Output: [0, 1, 2, 3] 
Visit 4 (neighbor of 2) → Final Output: [0, 1, 2, 3, 4] 
 */
import java.util.*;

public class BFSTraversal {
    public static void main(String[] args) {
        int[][] adj = {
            {1, 2},      
            {0, 2, 3},
            {0, 1, 4},
            {1, 4},  
            {2, 3}       
        };

        int vertexCount = adj.length;
        boolean[] visited = new boolean[vertexCount];
        Queue<Integer> queue = new LinkedList<>();
        List<Integer> traversal = new ArrayList<>();

        //  queue.add(0)
        // Throws an exception (IllegalStateException) if the queue is full.
        // Always adds the element if space is available.
        // queue.offer(0);
        // Returns false instead of throwing an exception if the queue is full.
        // Safer in some use-cases with capacity limits.

        queue.offer(0);
        visited[0] = true;

        while (!queue.isEmpty()) {
            int current = queue.poll();
            traversal.add(current);

            for(int neighbor : adj[current]){
                if(!visited[neighbor]){
                    visited[neighbor] = true;
                    queue.offer(neighbor);
                }
            }
        }
        System.out.println("BFS Traversal : " + traversal);
    }
}
