#include <bits/stdc++.h>
using namespace std;
 
class Solution{
    public:
   
    long long maxSubarraySum(int a[], int n){
        
        long long maxh = 0, maxf = a[0];
        
        
        for(int i=0;i<n;i++) 
            {
               
                maxh+=a[i];

                if(maxf<maxh)
                maxf=maxh; 
                
             
                if(maxh<0)
                    maxh=0;
    
            }
            
            return maxf;
        
    }
};

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}