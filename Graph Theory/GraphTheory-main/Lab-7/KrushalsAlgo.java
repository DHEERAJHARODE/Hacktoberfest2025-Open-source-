import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class KrushalsAlgo {
     static int[] parent;

    static int find(int i) {
        if (parent[i] == i)
            return i;
        return find(parent[i]);
    }
    static void union(int u, int v) {
        parent[find(u)] = find(v);
    }
    public static void main(String[] args) {
        int V = 4; 
        int[][] inputEdges = {
            {0, 1, 10},
            {0, 2, 6},
            {0, 3, 5},
            {1, 3, 15},
            {2, 3, 4}
        };
        List<Edge> edges = new ArrayList<>();
        for (int[] e : inputEdges) {
            edges.add(new Edge(e[0], e[1], e[2]));
        }
        Collections.sort(edges);
        parent = new int[V];
        for(int i=0;i<V;i++) parent[i] = i;
        System.out.println("Edges in the Minimum Spanning Tree");
        int totalWeight = 0;
        for(Edge e : edges){
            int u = e.src;
            int v = e.dest;
            if(find(u)!=find(v)){
                System.out.println(u+" - "+v+" : " + e.weight);
                totalWeight+=e.weight;
                union(u, v);
            }
        }
        System.out.println("Total Weight of MST : "+totalWeight);  
    }
}

class Edge implements Comparable<Edge> {
    int src, dest, weight;

    Edge(int s, int d, int w) {
        src = s;
        dest = d;
        weight = w;
    }

    public int compareTo(Edge other) {
        return this.weight - other.weight;
    }
}