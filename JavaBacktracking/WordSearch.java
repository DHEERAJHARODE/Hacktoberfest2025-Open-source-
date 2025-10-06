// Problem: Word Search in Grid
// Description: Check if a given word exists in a character grid.  
// You can move in 4 directions (up, down, left, right).

class WordSearch {
    static int ROW = 3, COL = 4;

    static boolean isSafe(int x, int y, boolean visited[][]) {
        return (x >= 0 && x < ROW && y >= 0 && y < COL && !visited[x][y]);
    }

    static boolean searchWord(char board[][], String word, int x, int y, int index, boolean visited[][]) {
        if (index == word.length())
            return true;

        if (!isSafe(x, y, visited) || board[x][y] != word.charAt(index))
            return false;

        visited[x][y] = true;

        // Explore 4 directions
        if (searchWord(board, word, x + 1, y, index + 1, visited) ||
            searchWord(board, word, x - 1, y, index + 1, visited) ||
            searchWord(board, word, x, y + 1, index + 1, visited) ||
            searchWord(board, word, x, y - 1, index + 1, visited)) {
            return true;
        }

        visited[x][y] = false; // BACKTRACK
        return false;
    }

    static boolean exist(char board[][], String word) {
        boolean visited[][] = new boolean[ROW][COL];

        for (int i = 0; i < ROW; i++)
            for (int j = 0; j < COL; j++)
                if (searchWord(board, word, i, j, 0, visited))
                    return true;

        return false;
    }

    public static void main(String args[]) {
        char board[][] = {
            {'A','B','C','E'},
            {'S','F','C','S'},
            {'A','D','E','E'}
        };

        String word1 = "ABCCED";
        String word2 = "SEE";
        String word3 = "ABCB";
