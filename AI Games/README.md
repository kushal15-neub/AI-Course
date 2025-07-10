# AI Games Collection – Challenge the Machine!

Welcome to **AI Games**, a collection of classic strategy games powered by intelligent decision-making algorithms. Whether you're trying to beat an unbeatable Tic Tac Toe bot, checkmating a smart Chess engine, or connecting four before a cunning AI opponent — this is your playground to test your wits against artificial intelligence.

---

## What's Inside?

Each game is a **complete implementation** featuring:

- Clean, modular Python source code 
- Built-in or GUI-based gameplay 
- AI logic using **Minimax**, **Alpha-Beta Pruning**, and smart heuristics 
- Instructions, dependencies, and gameplay screenshots 

---

### Games Included

| Game            | Mode      | AI Algorithm Used       | Interface   |
| --------------- | --------- | ----------------------- | ----------- |
| 🔲 Tic Tac Toe  | You vs AI | Minimax (Unbeatable AI) | Tkinter GUI |
| ♟️ Chess        | You vs AI | Minimax + Alpha-Beta    | Pygame GUI  |
| 🔴 Connect Four | You vs AI | Minimax + Alpha-Beta    | Terminal    |

---

## How to Run

### Prerequisites

- Python 3.x
- Some games require additional libraries (see below)

### Install Required Libraries

```bash
pip install pygame python-chess



Tic Tac Toe requires only built-in tkinter and math
Connect Four is fully terminal-based and needs no extra libraries


 Project Structure


AI_Games/
├── README.md ← Main README (overview of all games)
├── TicTacToe/
│ ├── tic_tac_toe.py     ← Main game code (rename from "Tik_Tak_Toe copy.py")
│ ├── README.md          ← Game-specific instructions
│ └── image/
│ ├── image-1.png
│ └── image.png
|  |__ image-2.png 
│

├── Chess/
│ ├── chess_ai.py            ← Rename from "Chess.py"
│ ├── README.md              ← Chess game documentation
│ └── images/
│ ├── chess1.png
│ └── chess2.png
│

├── ConnectFour/
│ ├── connect_four.py       ← Rename from "Connect_Four.py"
│ ├── README.md             ← Connect Four game documentation
│ └── images/
│ └── cn.png
| |__ cn2.png
| |__ cn3.png


```
# Screenshots

Each game folder contains an images/ folder with gameplay screenshots to give a quick preview.

# Algorithms Behind the Scenes

Minimax – Recursive strategy used in two-player games to minimize opponent's best outcome

Alpha-Beta Pruning – Smart optimization to skip unnecessary branches in Minimax

Board Evaluation – Heuristic scoring of game states (especially in Chess and Connect Four)

# Why This Project?

This collection showcases how AI can make optimal decisions even in simple games. It’s an educational and fun journey through classic AI search strategies.

# Perfect for:

Beginners learning game AI

Students studying Minimax logic

Showcasing skills in Python + Game AI


# Developed By

Kushal Panthadas
📍 North East University, Sylhet
🎓 CSE | Aspiring AI & Software Engineer
