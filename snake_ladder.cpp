class Solution {
public:
pair<int,int>getcoordinate(int value,int n){
    int r_top=(value-1)/n;
    int r_bottom=(n-1)-r_top;
    //for column
    int col=(value-1)%n;
    if((n%2==0&&r_bottom%2==0)||(n%2!=0&&r_bottom%2!=0)){
        col=(n-1)-col;
    }
    return {r_bottom,col};
}
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        vector<vector<int>>visited(n,vector<int>(n,0));
        queue<int>q;
        q.push(1);
        visited[n-1][0]=1;
        int steps=0;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int x=q.front();
                if(x==n*n)return steps;
            q.pop();
                for(int i=1;i<=6;i++){
                    if(x+i>n*n)break;
                    int value=x+i;
                    //find coordinates of value
                    pair<int,int>coordinate=getcoordinate(value,n);
                    int row=coordinate.first;
                    int col=coordinate.second;
                    if(visited[row][col]==1)continue;
                    if(board[row][col]==-1)q.push(value);
                    else{
                        value=board[row][col];   //either ladder  or snake
                        q.push(value);
                    }
                    //mark it visited
                    visited[row][col]=1;

                }
            }
            steps++;
        }
        return -1;
    }
};
