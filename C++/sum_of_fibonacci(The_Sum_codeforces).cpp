#include<bits/stdc++.h>
using namespace std;
 
int sum(int n){
    if(n==1){
        return 1;
    }
    if(n==2){
        return 2;
    }
    else{
        return sum(n-1)+sum(n-2)+1;
    }
}
int main(){
    int n;
    cin>>n;
cout<<sum(n)<<endl;
}
