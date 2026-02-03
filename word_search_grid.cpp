#include<bits/stdc++.h>
using namespace std;
bool search(int i, int j, int n, int m,vector<vector<char>>&grid, string word,int idx) // this depth first search function will search word in this grid 
    {
        if(idx==word.length())
        {
            return true;
        }
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]!=word[idx])
        {
            return false;
        }
        char temp=grid[i][j];
        grid[i][j]='.';
        bool ans=search(i,j-1,n,m,grid,word,idx+1) ||
        search(i,j+1,n,m,grid,word,idx+1) ||
        search(i+1,j,n,m,grid,word,idx+1) ||
        search(i-1,j,n,m,grid,word,idx+1);
        grid[i][j]=temp;
        return ans;
    }
bool solve(vector<vector<char>>& grid, string& word)
{
    int n=grid.size();
    int m=grid[0].size();
    for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]==word[0])
                {
                    if(search(i,j,n,m,grid,word,0))
                    {
                        return true;
                    }
                }
            }
        }
        return false;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>> grid(n,vector<char>(m,'.'));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>grid[i][j];
        }
    }
    string word;
    cin>>word;
    if(solve(grid,word)){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
    

}
