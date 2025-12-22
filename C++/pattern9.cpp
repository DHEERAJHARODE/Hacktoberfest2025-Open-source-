
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int i=1;
    while(i<=n)
    {
        
        int j=1;
        while(j<=n)
        {
            char ch='A'+j-1;
            cout<<ch<<" ";
            j++;
           
        }
         cout<<endl;
        i++;
    }
    return 0;
}