from typing import List

class Solution:
    def transpose(self, matrix: List[List[int]]) -> None:
        """
        Transpose a square matrix in-place (i.e., flip it over its diagonal).
        """
        n = len(matrix)
        for i in range(n):
            for j in range(i + 1, n):
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
