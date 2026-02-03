#include<bits/stdc++.h>
using namespace std;

int knapsack(int weight[], int value[], int cap, int n){
    if(n==0 || cap ==0){
        return 0;
    }
    if(weight[n-1]<=cap){
        return max(value[n-1] + knapsack(weight,value,cap - weight[n-1],n-1),
                    knapsack(weight,value,cap,n-1));
    }else{
       return knapsack(weight,value,cap,n-1);
    }
}
int main(){

    int weight[] = {1,2,4,5};
    int value[] = {1,3,5,7};
    int cap = 10;
    int n= 4;
    cout<<knapsack(weight,value,cap,n);

    return 0;

}