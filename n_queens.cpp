#include <bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, vector<string> &board, int n){

    int duprow=row;
    int dupcol=col;

    while(col>=0){
        if(board[row][col]=='Q'){ 
            return false;
        }
        col--;
    }

    row=duprow;
    col=dupcol;

    while(row>=0 && col>=0){
        if(board[row][col]=='Q'){ 
            return false;
        }
        row--;
        col--;
    }

    row=duprow;
    col=dupcol;

    while(row<n && col>=0){
        if(board[row][col]=='Q'){ 
            return false;
        }
        row++;
        col--;
    }
    return true;

}

void isCal(int col, vector<string> &board, int n, vector<vector<string>> &ans){
    if(col==n){
        ans.push_back(board);
        // cout<<ans.size()<<endl;
        // for(auto it : board){
        //     cout<<it<<" ";
        //     cout<<endl;
        // }
        return;
    }

    for(int row=0; row<n; row++){
        if(isSafe(row, col, board, n)){
            board[row][col]='Q';
            isCal(col+1, board, n, ans);
            board[row][col]='.';
        }
    }
}

int main(){
    int n;
    cin>>n;
    vector<string> board(n);
    string base(n, '.');
    for(int i=0; i<n; i++){
        board[i]=base;
    }
    vector<vector<string>> ans;

    isCal(0, board, n, ans);

    for(vector<string> vs : ans){
        for(string s : vs){
            
            cout<<s<<endl;
            // cout<<"check"<<endl;
        }
       
        cout<<endl;
    }
    cout<<ans.size();
    return 0;
}
