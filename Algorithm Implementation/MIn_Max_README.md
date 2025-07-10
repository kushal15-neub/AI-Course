 Minimax Algorithm

How the Algorithm Works

The Minimax algorithm is a recursive decision-making algorithm used in two-player zero-sum games like Chess, Tic Tac Toe, etc. It explores all possible moves and counter-moves in a game tree and picks the optimal path assuming both players play optimally.

Steps:
Generate game tree to a certain depth.

Maximizing Player (MAX) aims to get the maximum score.

Minimizing Player (MIN) aims to get the minimum score.

Recursively apply minimax():

At leaf nodes, return the score.

At MAX nodes, return the max of child values.

At MIN nodes, return the min of child values.

 Applications
Tic Tac Toe, Chess, Checkers, Connect-4

AI in games for turn-based decision making

Two-player adversarial games

Game tree analysis

Robot decision trees

⏱ Time & Space Complexity
Time Complexity:
O(b^d)
where b = branching factor, d = depth of the game tree

Space Complexity:
O(d)
(recursive stack for depth d)

You can reduce time complexity using Alpha-Beta Pruning.

🧪 Sample Input & Output



![alt text](images/image-12.png)



The graph:


![alt text](images/image-13.png)