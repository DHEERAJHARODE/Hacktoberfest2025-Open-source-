package graphs;
import java.util.ArrayList;
import java.util.List;
import java.util.Arrays;
public class DFS {
	int v;
	int e;
	int adj[][];
	public void newEdge(int start,int e)
	{
		adj[start][e]=1;
		adj[e][start]=1;
	}
	public void DFS(int start,boolean visited[])
	{
		System.out.println(start+" ");
		visited[start]=true;
		for(int i=0;i<v;i++)
		{
			if(adj[start][i]==1 && (!visited[i]))
			{
				DFS(i,visited);
				}
			}
		}
	public static void main(String[] args)
	{
		int v=8, e=8;
		DFS obj=new DFS(v,e);
		//Graph G(v,e);
		obj.newEdge(0,1);
		obj.newEdge(0,2);
		obj.newEdge(1,3);
		obj.newEdge(2,4);
		obj.newEdge(2,6);
		obj.newEdge(6,7);
		obj.newEdge(3,5);
		obj.newEdge(5,4);
		
		boolean[] visited=new boolean[v];
		Arrays.fill(visited,false);
		//Perform DFS
		obj.DFS(0,visited);
	}
	
	DFS(int v,int e)
	{
		this.v=v;
		this.e=e;
		adj=new int[v][e];
		for(int row=0;row<v;row++)
		{
			adj[row]=new int[v];
			for(int column=0;column<v;column++)
			{
				adj[row][column]=0;
			}
		}
	}}
