/*
Duplicate subtree in Binary Tree
Difficulty Level : Medium
Given a binary tree, find out whether it contains a duplicate sub-tree of size two or more, or not.
Note: Two same leaf nodes are not considered as subtree as size of a leaf node is one. 
Example 1 :
Input : 
               1
             /   \ 
           2       3
         /   \       \    
        4     5       2     
                     /  \    
                    4    5
Output : 1
Explanation : 
    2     
  /   \    
 4     5
is the duplicate sub-tree.
  
Example 2 :
Input : 
               1
             /   \ 
           2       3
Output: 0
Explanation: There is no duplicate sub-tree 
in the given binary tree.
*/

import java.util.LinkedList; 
import java.util.Queue; 
import java.io.*;
import java.util.*;

class Node{
    int data;
    Node left;
    Node right;
    Node(int data){
        this.data = data;
        left=null;
        right=null;
    }
}

class GFG {

    static Node buildTree(String str){

        if(str.length()==0 || str.charAt(0)=='N'){
            return null;
        }

        String ip[] = str.split(" ");
        // Create the root of the tree
        Node root = new Node(Integer.parseInt(ip[0]));
        // Push the root to the queue

        Queue<Node> queue = new LinkedList<>(); 

        queue.add(root);
        // Starting from the second element

        int i = 1;
        while(queue.size()>0 && i < ip.length) {

            // Get and remove the front of the queue
            Node currNode = queue.peek();
            queue.remove();

            // Get the current node's value from the string
            String currVal = ip[i];

            // If the left child is not null
            if(!currVal.equals("N")) {

                // Create the left child for the current node
                currNode.left = new Node(Integer.parseInt(currVal));
                // Push it to the queue
                queue.add(currNode.left);
            }

            // For the right child
            i++;
            if(i >= ip.length)
                break;

            currVal = ip[i];

            // If the right child is not null
            if(!currVal.equals("N")) {

                // Create the right child for the current node
                currNode.right = new Node(Integer.parseInt(currVal));

                // Push it to the queue
                queue.add(currNode.right);
            }
            i++;
        }

        return root;
    }
    static void printInorder(Node root){
        if(root == null)
            return;

        printInorder(root.left);
        System.out.print(root.data+" ");

        printInorder(root.right);
    }

	public static void main (String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t=Integer.parseInt(br.readLine());

        while(t > 0){
            String s = br.readLine();
	    	Node root = buildTree(s);

            Solution ob = new Solution();
    		System.out.println(ob.dupSub(root));
            t--;
        }
    }
}
// } Driver Code Ends


//User function Template for Java

/* A Binary Tree node
class Node
{
    int data;
    Node left, right;
    Node(int item)
    {
        data = item;
        left = right = null;
    }
}
 */

class Solution {
    int dupSub(Node root) {
        // code here 
        HashMap<String,Integer> hm = new HashMap<>();
        solve(root.left,hm);
        solve(root.right,hm);

        for(Map.Entry<String,Integer> e : hm.entrySet()) if(e.getValue()>1) return 1;
        return 0;
    }

    String solve(Node node, HashMap<String,Integer> hm){
        StringBuilder sb = new StringBuilder();
        if(node==null) return "n";
        if(node.right==null && node.left==null) return node.data+",";

        sb.append(solve(node.left,hm));
        sb.append(solve(node.right,hm));
        sb.append(node.data+",");
        String s = sb.toString();
        hm.put(s,hm.getOrDefault(s,0)+1);
        return s;
    }
}
