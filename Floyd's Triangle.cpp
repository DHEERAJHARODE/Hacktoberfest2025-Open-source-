//C++ to print the Floyd's Triangle.
/* 1
   01
   101
   0101 
   10101
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the value of n : ";
    //Input a number from user
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i>=j)
            {
                if((i+j)%2==0)
                {
                    cout<<"1";
                }
                else
                {
                    cout<<"0";
                }
            }
            else
            {
                cout<<" ";
            }
        }
        cout<<endl;
    }
}