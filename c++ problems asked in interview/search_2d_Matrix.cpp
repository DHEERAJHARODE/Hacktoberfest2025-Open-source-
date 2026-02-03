class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int key) {
     
    int i=0,j=0;
    int col=matrix[0].size();
    int row=matrix.size();
        
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			if(matrix[i][j]==key)
			{
                return 1;
            }
            else if(key<matrix[i][j])
            {
              break;
            }
            
		}
	} 
    
	return 0;
}
};