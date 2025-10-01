class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        col = set()
        Posdiag = set()
        Negdiag = set()

        res = []
        board = [["."] * n for i in range(n)]

        def backtrack(r):
            if r == n:
                copy = ["".join(row) for row in board]
                res.append(copy)
                return
            for c in range(n):
                if c in col or (r + c) in Posdiag or (r - c) in Negdiag:
                    continue
                col.add(c)
                Posdiag.add(r + c)
                Negdiag.add(r - c)
                board[r][c] = "Q"

                backtrack(r + 1)

                col.remove(c)
                Posdiag.remove(r + c)
                Negdiag.remove(r - c)
                board[r][c] = "."
        backtrack(0)
        return res
    
#N-Queens for Leetcode