#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
	ll nodes , edges ;
	cout <<"Enter Number of nodes in graph: ";
	cin >> nodes;
	cout << "Enter Number of edges in graph: ";
	cin >> edges;

	vector< vector<ll> > v(nodes+1);    // nodes+1 is taken as indexing starts from 0
	vector< bool > isVisited(nodes+1,false);   // For checking node traversed previously or not

	//Inputting the graph
	cout <<"Enter the pair of nodes containing edge with spaces in next "<<edges<<" line :\n";
	for(ll i = 1 ; i <= edges ; i++ ){
		ll x,y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
		//for directed edges you just need to comment one of these above line
	}
	
	vector<ll> distance(nodes+1,0),parent(nodes+1,-1);
	//distance vector stores minimum distance between the source vertex and the any vertex in it
	//parent vector stores the parent of any vertex if source vertex is taken as the root vertex
	ll source;
	cout << "\nEnter Source where the bfs starts from : ";
	cin>>source;
	isVisited[source] = true;
	queue <ll> q;    // Data Structure Queue is used to do BFS traversal in Graph
	q.push(source);

	cout <<"\nBFS Traversal is : ";
	while(!q.empty()){
		ll current=q.front();//current node stores the node which is traversed currntly
		q.pop();

		cout<<current<<" ";

		for(ll child : v[current]){

			if( ! isVisited[child] ){
				isVisited[child] = true;
				q.push(child);

				distance[child] = distance[current]+1; 
				parent[child] = current;
			}
		}
	}
	

	for(ll i = 1 ;i <= edges ; i++){
		cout <<"\nDistance between vertex "<< source <<" and vertex "<< i <<" is : " << distance[i];
	}
	for(ll i = 1 ;i <= edges ; i++){
		cout <<"\nParent of vertex "<< i <<" when source vertex is taken "<< source <<" : ";
		if( i == source ){
			cout <<"No Parent";
		}
		else cout << parent[i];
	}
	return 0;
}
