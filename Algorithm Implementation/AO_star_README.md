How the Algorithm Works
AO* is used for searching in AND-OR graphs, where:

OR branches: Choose one child

AND branches: All children must be satisfied

Key Concepts:
AO* combines DFS with heuristic estimation.

At each node:

It recursively explores all branches.

Chooses the branch (OR/AND) that gives minimum total cost.

It updates heuristic values of nodes dynamically (backtracking support).

Only expands the most promising nodes (best solution subgraph).


Applications
Expert systems & problem solvers (e.g., medical diagnosis)

Game AI (with compound goals)

Planning systems where multiple conditions must be met

Hierarchical task decomposition in robotics

Time & Space Complexity
Time Complexity:

Depends on branching structure, but in worst-case exponential:
O(b^d) where b = average branching factor and d = depth of tree

Space Complexity:
O(n) where n = number of nodes (due to recursion + memoization)


Sample Input & Output

![alt text](images/Ao.png)

The graph



![alt text](images/Ao_D.png)

