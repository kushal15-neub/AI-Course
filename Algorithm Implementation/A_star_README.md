A\* Search Algorithm
How the Algorithm Works:

A\* Search is an informed search algorithm that finds the shortest path between a start and goal node in a weighted graph, using a combination of:

Actual cost (g) from start to the current node

Heuristic cost (h) which estimates the cost from the current node to the goal

It evaluates nodes based on the total cost:
f(n) = g(n) + h(n)

Steps:

Start with the initial node and add it to a priority queue based on its f-value.

At each step, remove the node with the lowest f-value.

If it is the goal node, return the path.

Otherwise, expand its neighbors, update their g-values, and push them into the queue with updated paths.

Repeat until the goal is reached or the queue is empty.

Applications of A\* Algorithm:
Pathfinding in games (e.g., navigating NPCs in maps)

GPS Navigation systems

Robot motion planning

Network routing algorithms

AI planning problems

Solving puzzles (like 8-puzzle, sliding tiles, etc.)

Time & Space Complexity:

Time Complexity:
Best case: O(E) where E = number of edges (if heuristic is perfect)

Worst case: O(b^d) where b = branching factor, d = depth of the optimal path (exponential)

Space Complexity:
O(V) where V = number of vertices, because it stores g-values and paths for all visited nodes


Sample Input & Output (Screenshot Style)

![A star image](images/aag.png)

The graph:

![A star image](images/aaa.png)
