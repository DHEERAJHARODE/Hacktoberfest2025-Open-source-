#include <iostream>

using namespace std;



bool canWePlaceThatQueenSafeOnthat(int board[][10], int i, int j, int n)
{
    for(int row = 0; row < n; row++)
    {
        if(board[row][j] == 1 || board[i][row] == 1)  
        {
            return false;
        }
    }
    
    int x = i;
    int y = j;
    
    while(x >= 0 && y >= 0)
    {
        if(board[x][y] == 1) 
        {
            return false;
        }
        
        x--;
        y--;
    }
    
    x = i;
    y = j;
    
    while(x >= 0 && y < n)
    {
        if(board[x][y] == 1)
        {
            return false;
        }
        
        x--;
        y++;
    }

    return true;
    
}

bool nQueenSolverOnePrintOnly(int board[][10],int i, int n)
{
    if(i == n)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(board[i][j] == 1)
                {
                    cout << "Q  ";
                }
                else
                {
                    cout << "_  ";
                }
            }
            cout << endl;
        }
        
        cout << endl;
        
        
        return true;        
    }
    
    
    
    
    // Recursive Case 
    for(int j = 0; j < n; j++)
    {
        if(canWePlaceThatQueenSafeOnthat(board,i,j,n) == true)
        {
            board[i][j] = 1;
            
            
            bool queenAfterThatSubProblem = nQueenSolverOnePrintOnly(board,i+1,n);
            
            if(queenAfterThatSubProblem == true)
            {
                return true;
            }

            board[i][j] = 0;
        }
    }
    
    
    return false;
    
}




bool nQueenSolverAllPrint(int board[][10], int i, int n)
{
    // Base case 
    if(i == n)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(board[i][j] == 1)
                {
                    cout << "Q  ";
                }
                else
                {
                    cout << "_  ";
                }
            }
            
            cout << endl;
        }
        
        cout << endl << endl;
        
        return false;      
    }
    
    
    
    // Recursive case 
    for(int j = 0; j < n; j++)
    {
        if(canWePlaceThatQueenSafeOnthat(board,i,j,n) == true)
        {
            board[i][j] = 1;
            
            bool queenAfterThatSubProblem = nQueenSolverAllPrint(board,i+1,n);
            
            if(queenAfterThatSubProblem == true)
            {
                return true;
            }

            board[i][j] = 0;
        }
    }
    
    return false;
    
}




int main()
{
    int size;
    cout << "Enter size of board: ";
    cin >> size;
    
    int board[10][10] = {0};
    
    // nQueenSolverOnePrintOnly(board,0,size);
    
    cout << "All possible print " << endl;
    nQueenSolverAllPrint(board,0,size);

    return 0;
}
