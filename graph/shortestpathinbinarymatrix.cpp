#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int,pair<int,int>>>q;
        if(grid[0][0]==1 || grid[n-1][n-1]==-1)return -1;
        vector<vector<int>>dist(n,vector<int>(n,1e9));
        dist[0][0]=1;
        q.push({1,{0,0}});
        while(!q.empty()){
            auto top = q.front();
            int dis = top.first;
            int row = top.second.first;
            int col = top.second.second;
            q.pop();
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    int nrow = row + i;
                    int ncol = col + j;
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<n &&
                    grid[nrow][ncol]==0 && dis+1<dist[nrow][ncol]){
                        dist[nrow][ncol] =  dis+1;
                        q.push({dist[nrow][ncol],{nrow,ncol}});
                    }
                }
            }
        }      
        if(dist[n-1][n-1]==1e9){ 
            return -1;
        }
        return dist[n-1][n-1];
    }
};