Iterative Deepening Search (IDS)
✅ How the Algorithm Works:
IDS combines the space efficiency of Depth-First Search (DFS) and the optimality of Breadth-First Search (BFS). It repeatedly runs DLS with increasing depth limits until the goal is found or a maximum depth is reached.

🔄 Steps:
Loop over depth from 0 to max_depth.

For each depth:

Run a depth-limited DFS (DLS).

If the goal is found, stop and report the path.

If no goal found up to max_depth, report failure.

🧠 Applications of IDS
Artificial Intelligence: Search problems in games or puzzles (e.g., 8-puzzle).

Robot navigation: When the depth of the goal is unknown.

State space search problems: Large trees/graphs with unknown depth.

Memory-constrained environments: Because it uses O(d) space (like DFS), it's ideal where memory is limited.

⏱️ Time & Space Complexity
Time Complexity:
O(bᵈ) where:

b = branching factor

d = depth of the solution

Slightly more expensive than BFS due to repeated visits at shallow depths.

Space Complexity:
O(d) — DFS-style recursion with depth d.

🧪 Sample Input & Output



![alt text](image-11.png)



The graph:

![alt text](image-10.png)