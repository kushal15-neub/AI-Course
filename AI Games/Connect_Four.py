import random
import math

# Game configuration constants
ROWS = 6
COLUMNS = 7
EMPTY = " "
PLAYER_PIECE = "X"
COMPUTER_PIECE = "O"

# Create the game board as a 2D list
def create_board():
    return [[EMPTY for _ in range(COLUMNS)] for _ in range(ROWS)]

# Print the current state of the board
def print_board(board):
    for row in board:
        print("|" + "|".join(row) + "|")
    print(" " + " ".join(str(i) for i in range(COLUMNS)))

# Check if the top of the column is empty
def is_valid_location(board, col):
    return board[0][col] == EMPTY

# Get the next available row in a column from bottom up
def get_next_open_row(board, col):
    for r in range(ROWS - 1, -1, -1):
        if board[r][col] == EMPTY:
            return r
    return None

# Place the player's or computer's piece in the board
def drop_piece(board, row, col, piece):
    board[row][col] = piece

# Check all winning possibilities for a piece
def winning_move(board, piece):
    # Horizontal win
    for c in range(COLUMNS - 3):
        for r in range(ROWS):
            if all(board[r][c+i] == piece for i in range(4)):
                return True

    # Vertical win
    for c in range(COLUMNS):
        for r in range(ROWS - 3):
            if all(board[r+i][c] == piece for i in range(4)):
                return True

    # Positive diagonal win
    for c in range(COLUMNS - 3):
        for r in range(ROWS - 3):
            if all(board[r+i][c+i] == piece for i in range(4)):
                return True

    # Negative diagonal win
    for c in range(COLUMNS - 3):
        for r in range(3, ROWS):
            if all(board[r-i][c+i] == piece for i in range(4)):
                return True

    return False

# Return a list of columns where a piece can still be dropped
def get_valid_locations(board):
    return [col for col in range(COLUMNS) if is_valid_location(board, col)]

# Evaluate the usefulness of a 4-piece window
def evaluate_window(window, piece):
    score = 0
    opp_piece = PLAYER_PIECE if piece == COMPUTER_PIECE else COMPUTER_PIECE

    if window.count(piece) == 4:
        score += 100
    elif window.count(piece) == 3 and window.count(EMPTY) == 1:
        score += 10
    elif window.count(piece) == 2 and window.count(EMPTY) == 2:
        score += 5

    if window.count(opp_piece) == 3 and window.count(EMPTY) == 1:
        score -= 80

    return score

# Score the board for the given player to help the AI decide moves
def score_position(board, piece):
    score = 0

    # Score center column higher
    center_array = [board[r][COLUMNS // 2] for r in range(ROWS)]
    score += center_array.count(piece) * 6

    # Score horizontal windows
    for r in range(ROWS):
        row_array = [board[r][c] for c in range(COLUMNS)]
        for c in range(COLUMNS - 3):
            window = row_array[c:c + 4]
            score += evaluate_window(window, piece)

    # Score vertical windows
    for c in range(COLUMNS):
        col_array = [board[r][c] for r in range(ROWS)]
        for r in range(ROWS - 3):
            window = col_array[r:r + 4]
            score += evaluate_window(window, piece)

    # Score positive diagonals
    for r in range(ROWS - 3):
        for c in range(COLUMNS - 3):
            window = [board[r + i][c + i] for i in range(4)]
            score += evaluate_window(window, piece)

    # Score negative diagonals
    for r in range(3, ROWS):
        for c in range(COLUMNS - 3):
            window = [board[r - i][c + i] for i in range(4)]
            score += evaluate_window(window, piece)

    return score

# Check whether the game has ended
def is_terminal_node(board):
    return winning_move(board, PLAYER_PIECE) or winning_move(board, COMPUTER_PIECE) or len(get_valid_locations(board)) == 0

# Minimax algorithm with alpha-beta pruning
def minimax(board, depth, alpha, beta, maximizingPlayer):
    valid_locations = get_valid_locations(board)
    is_terminal = is_terminal_node(board)

    if depth == 0 or is_terminal:
        if is_terminal:
            if winning_move(board, COMPUTER_PIECE):
                return (None, 100000000000000)
            elif winning_move(board, PLAYER_PIECE):
                return (None, -10000000000000)
            else:
                return (None, 0)
        else:
            return (None, score_position(board, COMPUTER_PIECE))

    if maximizingPlayer:
        value = -math.inf
        best_col = random.choice(valid_locations)
        for col in valid_locations:
            row = get_next_open_row(board, col)
            temp_board = [r[:] for r in board]  # Make a deep copy of the board
            drop_piece(temp_board, row, col, COMPUTER_PIECE)
            new_score = minimax(temp_board, depth - 1, alpha, beta, False)[1]
            if new_score > value:
                value = new_score
                best_col = col
            alpha = max(alpha, value)
            if alpha >= beta:
                break
        return best_col, value
    else:
        value = math.inf
        best_col = random.choice(valid_locations)
        for col in valid_locations:
            row = get_next_open_row(board, col)
            temp_board = [r[:] for r in board]
            drop_piece(temp_board, row, col, PLAYER_PIECE)
            new_score = minimax(temp_board, depth - 1, alpha, beta, True)[1]
            if new_score < value:
                value = new_score
                best_col = col
            beta = min(beta, value)
            if alpha >= beta:
                break
        return best_col, value

# Get the best move for the computer using minimax
def get_computer_move(board):
    col, _ = minimax(board, 4, -math.inf, math.inf, True)
    return col

# Main game loop
def play_game():
    board = create_board()
    print_board(board)
    game_over = False
    turn = 0  # 0 = player, 1 = computer

    while not game_over:
        if turn % 2 == 0:
            # Player turn
            col = int(input("Player 1 Make your Selection (0-6): "))
            if is_valid_location(board, col):
                row = get_next_open_row(board, col)
                drop_piece(board, row, col, PLAYER_PIECE)

                if winning_move(board, PLAYER_PIECE):
                    print_board(board)
                    print("PLAYER 1 WINS!!")
                    game_over = True
        else:
            # Computer (AI) turn
            col = get_computer_move(board)
            if is_valid_location(board, col):
                row = get_next_open_row(board, col)
                drop_piece(board, row, col, COMPUTER_PIECE)

                if winning_move(board, COMPUTER_PIECE):
                    print_board(board)
                    print("COMPUTER WINS!!")
                    game_over = True

        print_board(board)

        # Check for draw
        if len(get_valid_locations(board)) == 0 and not game_over:
            print("GAME ENDS IN A DRAW!")
            game_over = True

        turn += 1

# Start the game
play_game()
