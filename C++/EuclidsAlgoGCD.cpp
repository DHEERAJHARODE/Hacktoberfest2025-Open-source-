#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b){

    if(a==0){
        return b;
    }
    if(b==0){
        return a;
    }
    while(a != b){
        if(a>b){
            a=a-b;
        }
        if(b>a){
            b=b-a;
        }
    }
    return a;
}

int main()
{
    int a,b;
    cout<<"Enter the values of a and b: "<<endl;
    cin>>a>>b;

    int ans=gcd(a,b);
    cout<<"The GCD of "<<a<<" & "<<b<<" is: "<<ans<<endl;

return 0;
}