# Import necessary libraries
import tkinter as tk
from tkinter import messagebox
import math
import random


class TicTacToe:
    def __init__(self, root):
        """Initialize the Tic-Tac-Toe game with the main window"""
        self.root = root
        self.root.title("Tic-Tac-Toe (You: X | Computer: O)")

        # Game board: 9 spaces initialized as empty
        self.board = [" " for _ in range(9)]
        # List to hold all button references
        self.buttons = []
        # Create the board UI
        self.create_board()

        # Player and computer symbols
        self.player = "X"
        self.computer = "O"

    def create_board(self):
        """Creates the 3x3 grid of buttons for the game"""
        for i in range(9):
            button = tk.Button(
                self.root,
                text=" ",                     # Button starts empty
                font="Helvetica 20 bold",     # Font styling
                height=3,
                width=6,
                command=lambda i=i: self.on_click(i),  # Link each button to on_click
            )
            button.grid(row=i // 3, column=i % 3)  # Place in grid
            self.buttons.append(button)  # Store reference

    def on_click(self, index):
        """
        Handle player's move when they click a button.
        Args:
            index (int): Index of the button clicked.
        """
        # Allow move only if cell is empty
        if self.board[index] == " ":
            self.make_move(index, self.player)

            # Check if player wins after the move
            if self.check_winner(self.player):
                messagebox.showinfo("Game Over", "You win!")
                self.reset_board()
                return
            # Check for draw
            elif self.is_draw():
                messagebox.showinfo("Game Over", "It's a draw!")
                self.reset_board()
                return

            # Delay before computer plays
            self.root.after(500, self.computer_move)

    def make_move(self, index, player):
        """
        Make a move for the given player at the given index.
        Args:
            index (int): Position to play.
            player (str): 'X' for player, 'O' for computer.
        """
        self.board[index] = player
        self.buttons[index]["text"] = player
        self.buttons[index]["state"] = "disabled"

    def is_draw(self):
        """Check if the board is full and there's no winner (draw)"""
        return " " not in self.board

    def check_winner(self, player):
        """
        Check if the specified player has won.
        Args:
            player (str): 'X' or 'O'
        Returns:
            bool: True if the player wins
        """
        # All possible winning lines (rows, cols, diagonals)
        win_combinations = [
            [0, 1, 2], [3, 4, 5], [6, 7, 8],  # Rows
            [0, 3, 6], [1, 4, 7], [2, 5, 8],  # Columns
            [0, 4, 8], [2, 4, 6]              # Diagonals
        ]
        return any(all(self.board[i] == player for i in combo) for combo in win_combinations)

    def available_moves(self):
        """Return a list of indices for empty cells (valid moves)"""
        return [i for i, spot in enumerate(self.board) if spot == " "]

    def computer_move(self):
        """
        Computer's turn to play:
        - 30% chance to play a random move (makes it beatable).
        - 70% chance to use Minimax for best move.
        """
        if random.random() < 0.3:
            # Make a random move (simulate imperfect AI)
            move = random.choice(self.available_moves())
        else:
            # Use Minimax to find the best move
            best_score = -math.inf
            best_move = None
            for move in self.available_moves():
                self.board[move] = self.computer
                score = self.minimax(0, False)
                self.board[move] = " "
                if score > best_score:
                    best_score = score
                    best_move = move
            move = best_move

        # Make the chosen move
        self.make_move(move, self.computer)

        # Check game result after computer's move
        if self.check_winner(self.computer):
            messagebox.showinfo("Game Over", "Computer wins!")
            self.reset_board()
        elif self.is_draw():
            messagebox.showinfo("Game Over", "It's a draw!")
            self.reset_board()

    def minimax(self, depth, is_maximizing):
        """
        Minimax algorithm: evaluates the best move recursively.
        Args:
            depth (int): Recursion depth.
            is_maximizing (bool): True if computer's turn, False if player's.
        Returns:
            int: Score for the current board state.
        """
        if self.check_winner(self.computer):
            return 1
        elif self.check_winner(self.player):
            return -1
        elif self.is_draw():
            return 0

        if is_maximizing:
            best_score = -math.inf
            for move in self.available_moves():
                self.board[move] = self.computer
                score = self.minimax(depth + 1, False)
                self.board[move] = " "
                best_score = max(score, best_score)
            return best_score
        else:
            best_score = math.inf
            for move in self.available_moves():
                self.board[move] = self.player
                score = self.minimax(depth + 1, True)
                self.board[move] = " "
                best_score = min(score, best_score)
            return best_score

    def reset_board(self):
        """Reset the board and buttons for a new round"""
        self.board = [" " for _ in range(9)]
        for btn in self.buttons:
            btn.config(text=" ", state="normal")


# Start the game
if __name__ == "__main__":
    root = tk.Tk()
    game = TicTacToe(root)
    root.mainloop()
