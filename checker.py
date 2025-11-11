import tkinter as tk
from tkinter import messagebox, ttk
from tkinter import font as tkFont

class CheckerGame:
    """A checkers game with GUI using tkinter"""
    
    BOARD_SIZE = 8
    SQUARE_SIZE = 60
    LIGHT_COLOR = "#F0D9B5"
    DARK_COLOR = "#B58863"
    HIGHLIGHT_COLOR = "#BACA44"
    
    def __init__(self, root):
        self.root = root
        self.root.title("Checkers Game")
        self.root.geometry("900x800")
        self.root.resizable(False, False)
        self.root.configure(bg="#2C2C2C")
        
        # Initialize game state
        self.board = [[' ' for _ in range(8)] for _ in range(8)]
        self.initialize_board()
        self.current_player = 'white'
        self.white_pieces = 12
        self.black_pieces = 12
        self.selected_square = None
        self.valid_moves = []
        
        # Create UI elements
        self.setup_ui()
        self.update_canvas()
        
    def initialize_board(self):
        """Set up the initial board with pieces"""
        # Place white pieces (bottom rows)
        for row in range(3):
            for col in range(8):
                if (row + col) % 2 == 1:
                    self.board[row][col] = 'w'
        
        # Place black pieces (top rows)
        for row in range(5, 8):
            for col in range(8):
                if (row + col) % 2 == 1:
                    self.board[row][col] = 'b'
    
    def setup_ui(self):
        """Set up the user interface"""
        # Top frame with title and status
        top_frame = tk.Frame(self.root, bg="#2C2C2C")
        top_frame.pack(fill=tk.X, padx=10, pady=10)
        
        title_font = tkFont.Font(family="Helvetica", size=20, weight="bold")
        title_label = tk.Label(top_frame, text="♟ CHECKERS GAME ♟", 
                              font=title_font, bg="#2C2C2C", fg="#FFD700")
        title_label.pack()
        
        # Info frame
        info_frame = tk.Frame(self.root, bg="#2C2C2C")
        info_frame.pack(fill=tk.X, padx=10, pady=5)
        
        info_font = tkFont.Font(family="Helvetica", size=12)
        
        self.status_label = tk.Label(info_frame, text="", font=info_font, 
                                     bg="#2C2C2C", fg="#00FF00")
        self.status_label.pack(side=tk.LEFT, padx=10)
        
        self.pieces_label = tk.Label(info_frame, text="", font=info_font,
                                    bg="#2C2C2C", fg="#FFFFFF")
        self.pieces_label.pack(side=tk.RIGHT, padx=10)
        
        # Board canvas
        board_frame = tk.Frame(self.root, bg="#2C2C2C")
        board_frame.pack(pady=10)
        
        self.canvas = tk.Canvas(
            board_frame,
            width=self.BOARD_SIZE * self.SQUARE_SIZE,
            height=self.BOARD_SIZE * self.SQUARE_SIZE,
            bg="#1A1A1A",
            highlightthickness=2,
            highlightbackground="#FFD700"
        )
        self.canvas.pack()
        self.canvas.bind("<Button-1>", self.on_square_click)
        
        # Button frame
        button_frame = tk.Frame(self.root, bg="#2C2C2C")
        button_frame.pack(fill=tk.X, padx=10, pady=10)
        
        button_font = tkFont.Font(family="Helvetica", size=10)
        
        reset_btn = tk.Button(button_frame, text="New Game", command=self.reset_game,
                             font=button_font, bg="#4CAF50", fg="white",
                             padx=15, pady=8, cursor="hand2")
        reset_btn.pack(side=tk.LEFT, padx=5)
        
        undo_btn = tk.Button(button_frame, text="Clear Selection", command=self.clear_selection,
                            font=button_font, bg="#2196F3", fg="white",
                            padx=15, pady=8, cursor="hand2")
        undo_btn.pack(side=tk.LEFT, padx=5)
        
        quit_btn = tk.Button(button_frame, text="Quit", command=self.root.quit,
                            font=button_font, bg="#f44336", fg="white",
                            padx=15, pady=8, cursor="hand2")
        quit_btn.pack(side=tk.LEFT, padx=5)
        
        # Instructions
        instructions_frame = tk.LabelFrame(self.root, text="Instructions", 
                                          bg="#2C2C2C", fg="#FFD700",
                                          font=("Helvetica", 9, "bold"))
        instructions_frame.pack(fill=tk.BOTH, padx=10, pady=5)
        
        instructions_text = """Click a piece to select it, then click a valid square to move.
White moves down (↓), Black moves up (↑). Kings can move any direction.
Capture opponent pieces by jumping over them. Reach the opposite end to become a King!"""
        
        instructions_label = tk.Label(instructions_frame, text=instructions_text,
                                     bg="#2C2C2C", fg="#CCCCCC",
                                     justify=tk.LEFT, font=("Helvetica", 8))
        instructions_label.pack(padx=10, pady=8)
        
        self.update_status()
    
    def draw_board(self):
        """Draw the checkerboard"""
        self.canvas.delete("all")
        
        # Draw squares
        for row in range(self.BOARD_SIZE):
            for col in range(self.BOARD_SIZE):
                x0 = col * self.SQUARE_SIZE
                y0 = row * self.SQUARE_SIZE
                x1 = x0 + self.SQUARE_SIZE
                y1 = y0 + self.SQUARE_SIZE
                
                # Determine square color
                if (row + col) % 2 == 0:
                    color = self.LIGHT_COLOR
                else:
                    color = self.DARK_COLOR
                
                # Highlight selected square
                if self.selected_square == (row, col):
                    color = self.HIGHLIGHT_COLOR
                
                # Highlight valid move squares
                if (row, col) in self.valid_moves:
                    color = "#FFDD00"
                
                self.canvas.create_rectangle(x0, y0, x1, y1, fill=color, outline="#333333")
    
    def draw_pieces(self):
        """Draw the game pieces on the board"""
        piece_font = tkFont.Font(family="Arial", size=24, weight="bold")
        
        for row in range(self.BOARD_SIZE):
            for col in range(self.BOARD_SIZE):
                piece = self.board[row][col]
                if piece != ' ':
                    x = col * self.SQUARE_SIZE + self.SQUARE_SIZE // 2
                    y = row * self.SQUARE_SIZE + self.SQUARE_SIZE // 2
                    
                    # Determine piece appearance
                    if piece == 'w':
                        symbol = "●"
                        color = "#FFFFFF"
                    elif piece == 'W':
                        symbol = "♔"
                        color = "#FFD700"
                    elif piece == 'b':
                        symbol = "●"
                        color = "#000000"
                    elif piece == 'B':
                        symbol = "♔"
                        color = "#FF6600"
                    
                    # Draw piece with shadow
                    self.canvas.create_text(x+1, y+1, text=symbol, font=piece_font,
                                          fill="#333333", tags="piece")
                    self.canvas.create_text(x, y, text=symbol, font=piece_font,
                                          fill=color, tags="piece")
    
    def update_canvas(self):
        """Update the canvas with board and pieces"""
        self.draw_board()
        self.draw_pieces()
    
    def update_status(self):
        """Update status labels"""
        player_color = "⚪ WHITE" if self.current_player == 'white' else "⚫ BLACK"
        self.status_label.config(text=f"Current Player: {player_color}")
        self.pieces_label.config(text=f"White: {self.white_pieces} | Black: {self.black_pieces}")
    
    def on_square_click(self, event):
        """Handle square click events"""
        col = event.x // self.SQUARE_SIZE
        row = event.y // self.SQUARE_SIZE
        
        if not (0 <= row < self.BOARD_SIZE and 0 <= col < self.BOARD_SIZE):
            return
        
        # If a square is already selected
        if self.selected_square:
            from_row, from_col = self.selected_square
            
            # If clicking the same square, deselect
            if (row, col) == self.selected_square:
                self.clear_selection()
                return
            
            # Try to move
            if (row, col) in self.valid_moves:
                self.move_piece(from_row, from_col, row, col)
            else:
                # Select a new piece
                self.select_piece(row, col)
        else:
            self.select_piece(row, col)
    
    def select_piece(self, row, col):
        """Select a piece and show valid moves"""
        piece = self.board[row][col]
        
        if piece == ' ':
            messagebox.showwarning("Invalid Selection", "No piece at this square!")
            return
        
        if (piece.lower() == 'w' and self.current_player != 'white') or \
           (piece.lower() == 'b' and self.current_player != 'black'):
            messagebox.showwarning("Invalid Selection", f"It's {self.current_player}'s turn!")
            return
        
        self.selected_square = (row, col)
        self.valid_moves = self.get_valid_moves(row, col, piece)
        self.update_canvas()
    
    def get_valid_moves(self, row, col, piece):
        """Get all valid moves for a piece"""
        valid_moves = []
        
        # Check all possible moves
        for new_row in range(self.BOARD_SIZE):
            for new_col in range(self.BOARD_SIZE):
                if self.is_valid_move(row, col, new_row, new_col, piece):
                    valid_moves.append((new_row, new_col))
        
        return valid_moves
    
    def is_valid_move(self, from_row, from_col, to_row, to_col, piece):
        """Check if a move is valid"""
        # Check bounds
        if not (0 <= to_row < self.BOARD_SIZE and 0 <= to_col < self.BOARD_SIZE):
            return False
        
        # Check if destination is on a dark square
        if (to_row + to_col) % 2 == 0:
            return False
        
        # Check if destination is empty
        if self.board[to_row][to_col] != ' ':
            return False
        
        row_diff = abs(to_row - from_row)
        col_diff = abs(to_col - from_col)
        
        # Regular move
        if row_diff == 1 and col_diff == 1:
            if piece.lower() == 'w' and to_row > from_row:
                return True
            elif piece.lower() == 'b' and to_row < from_row:
                return True
            elif piece.isupper():
                return True
        
        # Capture move
        elif row_diff == 2 and col_diff == 2:
            mid_row = (from_row + to_row) // 2
            mid_col = (from_col + to_col) // 2
            target_piece = self.board[mid_row][mid_col]
            
            if target_piece == ' ':
                return False
            
            if piece.lower() == 'w' and target_piece.lower() == 'w':
                return False
            if piece.lower() == 'b' and target_piece.lower() == 'b':
                return False
            
            if piece.lower() == 'w' and to_row > from_row:
                return True
            elif piece.lower() == 'b' and to_row < from_row:
                return True
            elif piece.isupper():
                return True
        
        return False
    
    def move_piece(self, from_row, from_col, to_row, to_col):
        """Execute a move"""
        piece = self.board[from_row][from_col]
        
        # Move the piece
        self.board[from_row][from_col] = ' '
        self.board[to_row][to_col] = piece
        
        # Handle capture
        row_diff = abs(to_row - from_row)
        if row_diff == 2:
            mid_row = (from_row + to_row) // 2
            mid_col = (from_col + to_col) // 2
            captured_piece = self.board[mid_row][mid_col]
            self.board[mid_row][mid_col] = ' '
            
            if captured_piece.lower() == 'w':
                self.white_pieces -= 1
            else:
                self.black_pieces -= 1
        
        # Promote to king
        if (piece == 'w' and to_row == 7) or (piece == 'b' and to_row == 0):
            self.board[to_row][to_col] = piece.upper()
        
        # Clear selection
        self.clear_selection()
        
        # Switch player
        self.current_player = 'black' if self.current_player == 'white' else 'white'
        
        # Check game over
        self.check_game_over()
        
        self.update_canvas()
        self.update_status()
    
    def clear_selection(self):
        """Clear the selected square and valid moves"""
        self.selected_square = None
        self.valid_moves = []
        self.update_canvas()
    
    def check_game_over(self):
        """Check if the game is over"""
        if self.white_pieces == 0:
            messagebox.showinfo("Game Over", "🎉 Black wins! All white pieces captured!")
            self.reset_game()
            return
        
        if self.black_pieces == 0:
            messagebox.showinfo("Game Over", "🎉 White wins! All black pieces captured!")
            self.reset_game()
            return
        
        if not self.has_valid_moves(self.current_player):
            winner = "White" if self.current_player == 'black' else "Black"
            messagebox.showinfo("Game Over", f"🎉 {winner} wins! {self.current_player.capitalize()} has no valid moves!")
            self.reset_game()
            return
    
    def has_valid_moves(self, player):
        """Check if a player has any valid moves"""
        piece_char = 'w' if player == 'white' else 'b'
        
        for row in range(self.BOARD_SIZE):
            for col in range(self.BOARD_SIZE):
                piece = self.board[row][col]
                if piece != ' ' and piece.lower() == piece_char:
                    for new_row in range(self.BOARD_SIZE):
                        for new_col in range(self.BOARD_SIZE):
                            if self.is_valid_move(row, col, new_row, new_col, piece):
                                return True
        return False
    
    def reset_game(self):
        """Reset the game"""
        self.board = [[' ' for _ in range(8)] for _ in range(8)]
        self.initialize_board()
        self.current_player = 'white'
        self.white_pieces = 12
        self.black_pieces = 12
        self.clear_selection()
        self.update_canvas()
        self.update_status()

def main():
    """Entry point of the game"""
    root = tk.Tk()
    game = CheckerGame(root)
    root.mainloop()

if __name__ == "__main__":
    main()
