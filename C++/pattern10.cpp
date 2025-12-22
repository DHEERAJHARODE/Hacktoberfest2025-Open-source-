
#include <iostream>
using namespace std;
int main()
{
    char ch='A';
    int n;
    cin>>n;
    int i=1;
    while(i<=n)
    {
        
        int j=1;
        while(j<=n)
        {
            
            cout<<ch<<" ";
            ch=ch+1;
            j++;
           
        }
         cout<<endl;
        i++;
    }
    return 0;
}