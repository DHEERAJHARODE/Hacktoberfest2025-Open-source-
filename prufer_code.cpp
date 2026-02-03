## Thus program prints the Prufer code of a tree.
## INPUT FORMAT 
## First line of the input specifies the number of vertices. Lines following are a pair of vertices (v1, v2) betweenwhich the edge is to be inserted. Read the edges until ‘$’ is encountered.

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    int n;
    cin>>n;
    int ar[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ar[i][j]=0;
        }
    }
    set<int>par;
    set<int>leaf;
    while(1){
        char a,b;
        cin>>a;
        if(a=='$'){
            break;
        }
        cin>>b;
        int c=a-'0';
        int d=b-'0';
        ar[c-1][d-1]=1;ar[d-1][c-1]=1;
        if(leaf.size()==0){
            leaf.insert(c);leaf.insert(d);
        }
        else{
            if(leaf.count(c)==1){
                auto it=leaf.lower_bound(c);
                leaf.erase(it);
                par.insert(c);
                leaf.insert(d);
            }
            else if(leaf.count(d)==1){
                auto it=leaf.lower_bound(d);
                leaf.erase(it);
                par.insert(d);
                leaf.insert(c);
            }
            else{
                if(par.count(c)==1){
                    leaf.insert(d);
                }
                else if(par.count(d)==1){
                    leaf.insert(c);
                }
                else{
                    leaf.insert(c);leaf.insert(d);
                }
            }
        }
    }
    for(int i=0;i<(n-2);i++){
        int a=*leaf.begin();
        leaf.erase(leaf.begin());
        int d;
        for(int i=0;i<n;i++){
            if(ar[a-1][i]==1){
                d=i+1;break;
            }
        }
        cout<<d<<" ";
        int v=0;
        for(int i=0;i<n;i++){
            if(ar[d-1][i]==1){
                v++;
            }
        }
        ar[d-1][a-1]--;
        ar[a-1][d-1]--;
        if(v<=2){
            leaf.insert(d);
            auto it=par.lower_bound(d);
            par.erase(it);
        }
    }
    return 0;
}
