
#include <iostream>
using namespace std;
int main()
{
    int count;
    int n;
    cin>>n;
    int i=1;
    while(i<=n)
    {
        
        int j=1;
        count=i;
        while(j<=i)
        {
            cout<<count<<" ";
            count=count-1;
            j++;
           
        }
         cout<<endl;
        i++;
    }
    return 0;
}