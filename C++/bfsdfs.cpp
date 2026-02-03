#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<vector<int>>graph;
vector<bool>visited;

void dfs(int v){
    visited[v]=true;
    cout<<v<<" ";

    for(int i=0;i<graph[v].size();++i)
    {
        int u=graph[v][i];
        if(!visited[u])
        {
            dfs(u);
        }
    }
}

void bfs(int v){
    queue<int>q;
    q.push(v);
    visited[v]=true;

    while(!q.empty())
    {
        int curr=q.front();
        q.pop();
        cout<<curr<<" ";

        for(int i=0;i<graph[curr].size();++i){
            int u=graph[curr][i];
            if(!visited[u])
            {
                visited[u]=true;
                q.push(u);
            }
        }
    }

}

int bfsSearch(int n,int v,int x)
{
    queue<int>q;
    visited[v]=true;
    q.push(v);

    while(!q.empty())
    {
        int curr=q.front();
        q.pop();
        
        for(int i=0;i<graph[curr].size();++i){
            int u=graph[curr][i];
            if(!visited[u])
            {
                visited[u]=true;
                q.push(u);
            }
        }
        cout<<curr<<" ";
        if(curr==x)
        {
            cout<<"Node is Found";
            return 1;
        }
    }
return 0;

}

int main(){
    int n,m;
    cout<<"Enter number of Vertices: ";
    cin>>n;
    cout<<"Enter number of edges: ";
    cin>>m;

    graph.resize(n);
    visited.resize(n,false);

    for(int i=0;i<m;++i){
        int u,v;
        cout<<"Enter an Edge(u v): ";
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    while(true)
    {
        cout<<"***************************\n";
        cout<<"1.DFS\n";
        cout<<"2.BFS\n";
        cout<<"3.Search\n";
        cout<<"4.Quit\n";

        int ch;
        cout<<"Enter Your Choice\n";
        cin>>ch;

        switch(ch)
        {
            case 1:
                cout<<"DEPTH FIRST SEARCH: ";
                for(int i=0;i<n;++i)
                {
                    if(!visited[i])
                    {
                        dfs(i);
                    }
                }
                break;
            case 2:
                visited.clear();
                visited.resize(n,false);
                cout<<"BREADTH FIRST SEARCH: ";
                for(int i=0;i<n;++i)
                {
                    if(!visited[i])
                    {
                        bfs(i);
                    }
                }
                break;
            case 3:
                visited.clear();
                visited.resize(n,false);
                int x;
                cout<<"Enter no:\n";
                cin>>x;
                int y;
                cout<<"SEARCH\n";
                y=bfsSearch(n,0,x);
                if(y==0)
                {
                    cout<<"NODE NOT FOUND";
                }
                break;

            default:
                cout<<"Thank you for using this program!!";
                break;

        }
    }
    return 0;
}