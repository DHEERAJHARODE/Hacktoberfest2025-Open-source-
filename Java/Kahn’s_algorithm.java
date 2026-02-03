import java.util.*;
 
// A class to store a graph edge
class Edge
{
    int src, dest;
 
    public Edge(int src, int dest)
    {
        this.src = src;
        this.dest = dest;
    }
}
 
// A class to represent a graph object
class Graph
{
    // A list of lists to represent an adjacency list
    List<List<Integer>> adjList = null;
 
    // stores indegree of a vertex
    List<Integer> indegree = null;
 
    // Constructor
    Graph(List<Edge> edges, int n)
    {
        adjList = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            adjList.add(new ArrayList<>());
        }
 
        // initialize indegree of each vertex by 0
        indegree = new ArrayList<>(Collections.nCopies(n, 0));
 
        // add edges to the directed graph
        for (Edge edge: edges)
        {
            int src = edge.src;
            int dest = edge.dest;
 
            // add an edge from source to destination
            adjList.get(src).add(dest);
 
            // increment in-degree of destination vertex by 1
            indegree.set(dest, indegree.get(dest) + 1);
        }
    }
}
 
class Main
{
    // Function to perform a topological sort on a given DAG
    public static List<Integer> doTopologicalSort(Graph graph, int n)
    {
        // list to store the sorted elements
        List<Integer> L = new ArrayList<>();
 
        // get in-degree information of the graph
        List<Integer> indegree = graph.indegree;
 
        // Set of all nodes with no incoming edges
        Stack<Integer> S = new Stack<>();
        for (int i = 0; i < n; i++)
        {
            if (indegree.get(i) == 0) {
                S.add(i);
            }
        }
 
        while (!S.isEmpty())
        {
            // remove node `i` from `S`
            int i = S.pop();
 
            // add `i` at the tail of `L`
            L.add(i);
 
            for (int m: graph.adjList.get(i))
            {
                // remove an edge from `n` to `m` from the graph
                indegree.set(m, indegree.get(m) - 1);
 
                // if `m` has no other incoming edges, insert `m` into `S`
                if (indegree.get(m) == 0) {
                    S.add(m);
                }
            }
        }
 
        // if a graph has edges, then the graph has at least one cycle
        for (int i = 0; i < n; i++)
        {
            if (indegree.get(i) != 0) {
                return null;
            }
        }
 
        return L;
    }
 
    public static void main(String[] args)
    {
        // List of graph edges as per the above diagram
        List<Edge> edges = Arrays.asList(
                new Edge(0, 6), new Edge(1, 2), new Edge(1, 4),
                new Edge(1, 6), new Edge(3, 0), new Edge(3, 4),
                new Edge(5, 1), new Edge(7, 0), new Edge(7, 1)
        );
 
        // total number of nodes in the graph (labelled from 0 to 7)
        int n = 8;
 
        // build a graph from the given edges
        Graph graph = new Graph(edges, n);
 
        // Perform topological sort
        List<Integer> L = doTopologicalSort(graph, n);
 
        if (L != null) {
            System.out.print(L);    // print topological order
        }
        else {
            System.out.println("Graph has at least one cycle. " +
                    "Topological sorting is not possible");
        }
    }
}
