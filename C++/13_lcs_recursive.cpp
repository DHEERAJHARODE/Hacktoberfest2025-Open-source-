#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
#define ll long long int

int lcs(string s1,string s2,int n,int m){
    if(n==0 || m == 0){
        return 0;
    }

    if(s1[n-1] == s2[m-1]){
        return 1+lcs(s1,s2,n-1,m-1);
    }else{
        return max(lcs(s1,s2,n,m-1) , lcs(s1,s2,n-1,m));
    }
}
int main()
{
    string s1 = "abcfeh";
    string s2 = "abefh";
    int n = s1.length();
    int m = s2.length();
    cout<<lcs(s1,s2,n,m)<<endl;
}