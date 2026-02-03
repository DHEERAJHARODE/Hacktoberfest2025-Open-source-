#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
#define ll long long int

const int N=1e3+10;
int static t[N][N]; 

int knapsack(int weight[],int value[],int cap,int n){
    if(n== 0 || cap == 0){
        return 0;
    }

    if(t[n][cap] != -1){
        return t[n][cap];
    }

    if(weight[n-1]<=cap){
        return t[n][cap] = max(value[n-1] + knapsack(weight,value,cap - weight[n-1],n-1) , 
                    knapsack(weight,value,cap,n-1));
    }else{
        return t[n][cap] = knapsack(weight,value,cap,n-1);
    }

    return t[n][cap];
}

int main()
{
    int weight[] = {1,2,4,5};
    int value[] = {1,3,5,7};
    int n= 4;
    int cap = 10;
    memset(t,-1,sizeof(t));
    cout<<knapsack(weight,value,cap,n)<<endl;;
    for(int i=0;i<n+1;i++){
        for(int j=0;j<cap+1;j++){
            cout<<t[i][j]<<" ";
        }
        cout<<endl;
    }
}