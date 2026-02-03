#include<iostream>
#include<string>
#include <cstring>
 
 
using namespace std;
 
 
 
void solve()
{
       int n,m;
        cin >> n >> m;
        int row[m],col[m],checr[n+1],checc[n+1];
        memset(checr,0,sizeof(checr));
        memset(checr,0,sizeof(checc));
 
        for(int i=0;i<m;i++)
        {
            cin >> row[i] >> col[i];
            checr[row[i]]++;
            checc[col[i]]++;
        }
        int c=0,d=0,cnt=0;
        for(int i=0;i<m;i++)
        {
            int a=row[i];
            int b=col[i];
            for(int j=1;j<=n;j++)
            {
                if(j!=a)
                {
                    if(!checr[j])
                    {
                        cout << "YES" << "\n";
                        return ;
                    }
                }
            }
            for(int k=1;k<=n;k++)
            {
                if(k!=b)
                {
                    if(!checc[k])
                    {
                        cout << "YES" << "\n";
                        return ;
                    }
                }
            }
            
        }
        cout << "NO" << "\n";
}
 
int main()
{
 
    // return sumcousins(A,k);
    int t;
    cin >> t;
 
    while(t--)
    {
        solve();
    }
}