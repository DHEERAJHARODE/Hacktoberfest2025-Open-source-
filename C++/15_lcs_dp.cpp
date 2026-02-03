#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
#define ll long long int

const int N = 1e3+10;
static int t[N][N];

int lcs(string s1, string s2, int n,int m){
    
    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            if(i==0 || j==0){
                t[i][j] = 0;
            }
        }
    }
    for(int i = 1 ;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(s1[i-1] == s2[j-1]){
                t[i][j] =  1 + t[i-1][j-1];
            }else{
                t[i][j] = max(t[i-1][j] , t[i][j-1]);
            }
        }
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