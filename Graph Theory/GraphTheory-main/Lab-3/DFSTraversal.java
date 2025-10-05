/*Prob. 1 Perform a Depth First Search (DFS) traversal starting from vertex 0, visiting vertices from left to 
right according to the adjacency list, and return a list containing the BFS traversal of the graph.  
Input: adj =  [[1, 2], [0, 2], [0, 1, 3, 4], [2], [2]] 
 
 
 
Output: [0 1 2 3 4] 
Explanation:  The source vertex s is 0. We visit it first, and then we visit an adjacent.  
Start at 0: Mark as visited. Output: 0 
Move to 1: Mark as visited. Output: 1  
Move to 2: Mark as visited. Output: 2  
Move to 3: Mark as visited. Output: 3 (backtrack to 2) 
Move to 4: Mark as visited. Output: 4 (backtrack to 2, then backtrack to 1, then to 0) 
4 Prob. 1 In a social network of N people, some of them are directly connected as friends. If person 
*/

import java.util.*;

public class DFSTraversal{
    public static void main(String[] args) {
        int adj[][] =  {{1, 2}, {0, 2}, {0, 1, 3, 4}, {2}, {2}};

        int vertexCount = adj.length;
        boolean visited[] = new boolean[vertexCount];
        Stack<Integer> stack = new Stack<>();
        List<Integer> traversal = new ArrayList<>();

        stack.push(0);
        while (!stack.isEmpty()) {
            int current = stack.pop();

            if(!visited[current]){
                visited[current] = true;
                traversal.add(current);

                int neighbors[] = adj[current];
                for(int i=neighbors.length-1; i>=0; i--){
                    int neighbor = neighbors[i];

                    if(!visited[neighbor]){
                        stack.push(neighbor);
                    }
                }
            }
        }
        System.out.println("DFS Traversal : " + traversal);
    }
}