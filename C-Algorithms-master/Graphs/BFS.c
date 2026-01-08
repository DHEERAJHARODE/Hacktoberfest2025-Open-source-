// BFS implementation using queue

#include <stdio.h>
#include <stdlib.h>

void bfs(int m[10][10], int v, int source)
{
    /// A queue will be used during the traversal
    int queue[20];
    int front = 0;
    int rear = 0;

    /// Temporary variables
    int u, i;

    // Array to maintain the visited vertices initialized to 0
    int visited[10];
    for (i= 0; i < v; i ++)
        visited[i] = 0;

    // Initialize the queue with source and mark it visited
    queue[rear] = source;
    visited[source] = 1;

    printf("The BFS Traversal is... \n");

    // Loop until the queue is empty
    while (front <= rear)
    {
        // Pick the vertex from front of the queue
        // This is also when we mark the traversal and print it
        u = queue[front];
        printf("%d\t", u);

        // Update front
        front += 1;

        /// All the vertices that are reachable from considered vertex
        /// and not yet visited,
        /// Mark them as visited and Add them to queue
        for(i=0;i<v;i++)
        {
            if(m[u][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                rear += 1;
                queue[rear] = i;
            }
        }
    }
}

int main()
{
    // Variable to hold the number of vertices
    int v = 5;

    // Variable to hold the graph as matrix (Adjacency Matrix)
    int m[10][10] =
                    {
                        {0, 1, 1, 0, 0},
                        {1, 0, 0, 1, 1},
                        {1, 0, 0, 0, 1},
                        {0, 1, 0, 0, 0},
                        {0, 1, 1, 0, 0}
                    };

    // Variable to hold source vertex
    int source = 4;
    
    printf("The vertices are: ");
    for(int i=0; i<v; i++){
        printf("%d ",i);
    }
    printf("\nThe source vertex is %d\n",source);
    
    // Call the bfs traversal
    bfs(m, v, source);

    return 0;
}
