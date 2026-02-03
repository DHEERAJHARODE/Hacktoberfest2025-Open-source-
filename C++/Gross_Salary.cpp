#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int a;
        cin>>a;
        long double hr,da,gs;
        if (a<1500)
        {
            hr=a*(.1);
            da=a*(.9);
        }
        else
        {
            hr=500;
            da=a*(.98);
        }
        gs=hr+da+a;
        cout<<fixed<<setprecision(2)<<gs<<endl;
    }
    return 0;
}
