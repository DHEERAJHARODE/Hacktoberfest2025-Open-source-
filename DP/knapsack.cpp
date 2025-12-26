#include<bits/stdc++.h>
#include <iostream>

using namespace std;

int knapSack(int W,int value[],int weight[],int n)
{
    if(W==0 || n==0)
    return 0;
    
    if(weight[n-1]>W)
        return(W,value,weight,n-1);
    else
        return(max( (value[n-1])+knapSack(W-weight[n-1],value,weight,n-1) ,knapSack(W,value,weight,n-1)));
}

int main()
{
    int value[]={60,100,120};
    int weight[]={10,20,30};
    
    int n=sizeof(value)/sizeof(value[0]);
    int W=50;
    cout<<"The maximum profit value is : "<<knapSack(W,value,weight,n);
    return 0;
}

