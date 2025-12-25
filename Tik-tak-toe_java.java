import java.util.Scanner;

public class TicTacToeGame {
    public static void main(String[] args) {
        char[][] board = {
            {' ', ' ', ' '},
            {' ', ' ', ' '},
            {' ', ' ', ' '}
        };
        
        char currentPlayer = 'X';
        boolean gameWon = false;
        
        while (true) {
            printBoard(board);
            System.out.println("Player " + currentPlayer + ", enter row (0-2) and column (0-2): ");
            int row = getUserInput("Row: ");
            int col = getUserInput("Column: ");
            
            if (board[row][col] == ' ') {
                board[row][col] = currentPlayer;
                gameWon = checkWin(board, currentPlayer);
                if (gameWon) {
                    printBoard(board);
                    System.out.println("Player " + currentPlayer + " wins!");
                    break;
                }
                
                if (currentPlayer == 'X') {
                    currentPlayer = 'O';
                } else {
                    currentPlayer = 'X';
                }
            } else {
                System.out.println("Cell already occupied. Try again.");
            }
        }
    }

    public static void printBoard(char[][] board) {
        System.out.println("-------------");
        for (int i = 0; i < 3; i++) {
            System.out.print("| ");
            for (int j = 0; j < 3; j++) {
                System.out.print(board[i][j] + " | ");
            }
            System.out.println("\n-------------");
        }
    }

    public static int getUserInput(String prompt) {
        Scanner scanner = new Scanner(System.in);
        int input;
        do {
            System.out.print(prompt);
            while (!scanner.hasNextInt()) {
                System.out.print("Invalid input. " + prompt);
                scanner.next();
            }
            input = scanner.nextInt();
        } while (input < 0 || input > 2);
        return input;
    }

    public static boolean checkWin(char[][] board, char player) {
        // Check rows, columns, and diagonals for a win
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
                return true; // Row win
            }
            if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
                return true; // Column win
            }
        }
        if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
            return true; // Diagonal win
        }
        if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
            return true; // Diagonal win
        }
        return false;
    }
}
