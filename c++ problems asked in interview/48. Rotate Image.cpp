/* You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

Example 1:

Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]

Example 2:

Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]


Solution :
Time Complexity : O(n^2) where n is the size of the matrix. 
Space Complexity : O(1) because we have to solve it inplace.
*/


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int i,j,n,temp;
        n = matrix.size();
        //transpose the matrix along the diagonal
        for(i=0;i<n;i++){
            for(j=i+1;j<n;j++) {
                temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        
        //reverse the matrix
        for(i=0;i<n;i++) {
            for(j=0;j<n/2;j++){
                temp = matrix[i][j];
                matrix[i][j] = matrix[i][n-1-j];
                matrix[i][n-1-j] = temp;
            }
        }
        
            
    }
};