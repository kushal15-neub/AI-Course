 Greedy Best-First Search (GBFS)
✅ How the Algorithm Works:
Greedy Best-First Search selects the next node to expand based only on the heuristic estimate (h(n)), not the cost from the start (g(n)).

Steps:
Start from the start node.

Use a priority queue to always choose the node with the lowest heuristic value.

For each node:

If it’s the goal, return the path.

Otherwise, expand its unvisited neighbors and add them to the queue.

Track parents to reconstruct the path.

Important: GBFS is fast but not optimal or complete, unlike A*.

🧠 Applications
Route planning (when speed is more important than optimality)

Real-time pathfinding in games

Simple decision-making agents

⏱️ Time and Space Complexity
Time Complexity:
O(E + V log V) (with priority queue and adjacency list)

Space Complexity:
O(V) for visited array, parent tracking, and priority queue

🧪 Sample Input & Output



![alt text](images/image-6.png)


The graph:


![alt text](images/image-7.png)