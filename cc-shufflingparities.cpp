//https://www.codechef.com/problems/SHUFFLIN

#include<bits/stdc++.h>
using namespace std;
int main()
{   int t;                                  // test cases
    cin>>t;
    while(t--)
    {  
        int n;                              //number of integers
        cin>>n;
        int a[n];

        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        int e=0,o=0;                    // e for even number ,  o for odd number
        for (int i = 0; i < n; i++)
        {
            if(a[i]%2==0)
            e++;
            else
            o++;
        }
        int ne=n/2;                     // number of even indices
        int no=n-ne;                    // number of odd indices
        cout<<min(e,no)+min(o,ne)<<endl;        
        
    }
  return 0;
}