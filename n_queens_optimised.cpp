#include <bits/stdc++.h>
using namespace std;

void isCal(int col, vector<int> &upperdiagonal, vector<int> &lowerdiagonal, vector<int> &leftrow, vector<string> &board, vector<vector<string>> &ans, int n){
    if(col==n){
        ans.push_back(board);
        cout<<"check"<<endl;
        return;
    }

    // for(int row=0; row<n; row++){
    //     if(leftrow[row]==0 && lowerdiagonal[col+row]==0 && upperdiagonal[n-1 + col-row]==0){
    //         board[row][col]='Q';
    //         upperdiagonal[n-1 + col-row]=1;
    //         lowerdiagonal[col+row]=1;
    //         leftrow[row]=1;
    //         isCal(col+1, upperdiagonal, lowerdiagonal, leftrow, board, ans, n);
    //         board[row][col]='.';
    //         upperdiagonal[n-1 + col-row]=0;
    //         lowerdiagonal[col+row]=0;
    //         leftrow[row]=0;
    //     }
    // }

    for(int row=0;row<n;row++){
        if(leftrow[row]==0 && lowerdiagonal[row+col]==0 && upperdiagonal[n-1 + col-row]==0){
            board[row][col]='Q';
            leftrow[row]=1;
            lowerdiagonal[row+col]=1;
            upperdiagonal[n-1+col-row]=1;
            isCal(col+1, upperdiagonal, lowerdiagonal, leftrow, board, ans, n);
            board[row][col]=
            leftrow[row]=0;
            lowerdiagonal[row+col]=0;
            upperdiagonal[n-1+col-row]=0;
        }
    } 
}



int main(){
    int n;
    cin>>n;
    vector<string> board(n);
    string base(n,'.');
    for(int i=0; i<n; i++){
        board[i]=base;
    }
    vector<vector<string>> ans;
    vector<int> upperdiagonal(2*n-1,'0');
    vector<int> lowerdiagonal(2*n-1,'0');
    vector<int> leftrow(n,'0');
    isCal(0,upperdiagonal,lowerdiagonal,leftrow,board,ans, n);
    for(vector<string> v : ans){
        for(string s : v){
            cout<<s<<" ";
        }
        cout<<endl;
    }
    return 0;
}
