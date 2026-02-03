//   1
//  121
// 12321
//1234321
#include<iostream>
using namespace std;
int main()
{
 int n;
 cin>>n;
 int i = 1;
 while(i<=n){
    int space = n-i;
    while(space){
        cout<<" ";
        space--;
    }
    int j=1;
    int num = 1;
    while(j<=i){
        cout<<num;
        num++;
        j++;
    }
    int k = 1;
    int num2 = i-1;
    while(k<=i-1){
        cout<<num2;
        num2--;
        k++;
    }
    cout<<endl;
    i++;
 }   
 return 0;
}