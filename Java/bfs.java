import java.util.*;

 public class bfs { 
static int v,e;
    static int[][] m;
	public static void main(String[] args) throws NumberFormatException {
        
        /* Write Your Code Here
		 * Complete the Rest of the Program
		 * You have to take input and print the output yourself
		 */
        Scanner sc=new Scanner(System.in);
        //System.out.println("Enter no. of Vertices:");
        v=sc.nextInt();  e=sc.nextInt();
        if(v==0)
        {
            System.exit(0); //for no vertices, exit
        }
        else if(e==0)
        {
            for(int i=0;i<v;i++)
            {
                 System.out.print(i+" "); //for no edge, only vertices, print all vertices
                
            }
            System.exit(0);
        }
        //e=sc.nextInt();
        m=new int[v+1][v+1];
        //int[][] m=new int[v+1][v+1];
        for(int i=0;i<v;i++)
        {
            for(int j=0;j<v;j++)
            {
                m[i][j]=0;
            }
        }
        
        for(int i=0;i<e;i++)
        {   int v1=sc.nextInt();  int v2=sc.nextInt();
            addEdge(v1,v2);
        }
        

    
        bfsF();
	}
    static void addEdge(int source, int destination)
    {
        m[source][destination]=1;
        m[destination][source]=1;
    }
    static void bfsF()
    {
        int visited[]=new int[v+1];
        for(int i=0;i<v;i++)
        {visited[i]=0;  //since initially no vertex is visited
        }
        Queue<Integer> q = new LinkedList<Integer>();
        q.add(0);
        visited[0]=1;
        
        
        while(!q.isEmpty())
        {
            int u=q.remove();
            System.out.print(u+" ");
            for(int i=0;i<v;i++) //beginning from 1 since 0 has been already explored as default case
            {if(m[u][i]==1 && visited[i]==0)
                {
                    q.add(i);
                    visited[i]=1;
                }
            }

        }
    }

}


