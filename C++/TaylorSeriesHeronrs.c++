#include<bits/stdc++.h>
using namespace std;
double HTS(double x,double n)
{
    static double s = 1;
    if(n==0) return s;
    else
    {
        s = 1+ (x/n)*s;
        return HTS(x,n-1);
    }
}
int main()
{
    double x,n;
    cin>>x>>n;
    cout<<HTS(x,n)<<endl;

}