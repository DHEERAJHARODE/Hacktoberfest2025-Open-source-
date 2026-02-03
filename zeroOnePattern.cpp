#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            /* if(((i%2==0)&&(j%2==0)) || ((i%2!=0)&&(j%2!=0)))
            {
                cout<<"1 ";
            }
            else
            {
                cout<<"0 ";
            } */

            // Another way to print this pattern
            if((i+j)%2==0)
            {
                cout<<"1 ";
            }
            else
            {
                cout<<"0 ";
            }
        }
        cout<<endl;
    }
}