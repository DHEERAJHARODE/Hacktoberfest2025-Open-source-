#include<iostream>
#include<queue>
#define ll long long
using namespace std;
int main()
{   int t;
    cin>>t;
    while(t--)
    {
    	int n,i,x,y,flag=0;
    	ll c=0;
    	ll z;
    	cin>>n>>z;
    	
    	priority_queue <int> g;
    	
    	for(i=0;i<n;i++)
    	{   cin>>x;
    		g.push(x);
		}
		
		while(z>0)
		{  if(g.top()==0)
		 {
		 	cout<<"Evacuate"<<endl;
		 	
		 	flag=1;
		 	break;
		 	
		 } 
		else{
		
			z=z-g.top();
			y=g.top()/2;
			g.pop();
			g.push(y);
			c++;
		}
		}
		if(flag==1)
		{
		}
		else
		cout<<c<<endl;
    	
	}

}
