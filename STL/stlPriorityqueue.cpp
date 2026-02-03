#include<bits/stdc++.h>
#include<queue>
using namespace std;

int main()
{

    priority_queue<int> p;

    p.push(1);
    p.push(2);
    p.push(3);
    p.push(0);
    int n = p.size();

    for(int i=0;i<n;i++)
    {
        cout<<p.top()<<" ";
        p.pop();
    }


}