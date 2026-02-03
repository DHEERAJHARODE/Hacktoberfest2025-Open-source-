#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
#define ll long long int

const int N = 1e3+10;
static int t[N][N];

int lcs(string s1, string s2, int n,int m){
    if(n==0 || m==0){
        return 0;
    }
    
    if(t[n][m] != -1){
        return t[n][m];
    }

    if(s1[n-1] == s2[m-1]){
        return t[n][m] =  1 + lcs(s1,s2,n-1,m-1);
    }else{
        return t[n][m] = max(lcs(s1,s2,n-1,m) , lcs(s1,s2,n,m-1));
    }

    return t[n][m];
}

int main()
{
    string s1 = "abcfeh";
    string s2 = "abefh";
    int n = s1.length();
    int m = s2.length();
    memset(t,-1,sizeof(t));
    cout<<lcs(s1,s2,n,m)<<endl;

    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            cout<<t[i][j]<<" ";
        }
        cout<<endl;
    }
}