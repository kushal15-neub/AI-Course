Alpha-Beta Pruning

How the Algorithm Works:
Alpha-Beta Pruning is an optimization of the Minimax algorithm used in decision-making and game theory. It prunes branches in the game tree that don't affect the final decision, which saves time.

Key Concepts:
Alpha: Best value that the maximizer can guarantee so far.

Beta: Best value that the minimizer can guarantee so far.

Pruning: If the current branch can't improve the outcome, it is skipped.

Flow:
Begin at the root (depth 0, maximizer).

Recursively evaluate child nodes down to the leaf nodes.

Backtrack, propagating the min/max values.

If beta <= alpha at any point, prune that subtree.

 Applications:
AI in games like Chess, Tic-Tac-Toe, Checkers

Adversarial search problems

Two-player turn-based games

Decision-making trees in Game AI engines

 Time & Space Complexity:
  Time Complexity:
Worst case (no pruning): O(b^d)

Best case (with optimal pruning): O(b^(d/2))
Where b = branching factor, d = depth

 Space Complexity:
O(d) due to recursion stack.

Sample Input & Output

![alt text](images/alpha.png)

The graph:

![alt text](images/alphagraph.png)
