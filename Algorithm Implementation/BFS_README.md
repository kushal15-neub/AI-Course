Breadth-First Search (BFS)
How the Algorithm Works
BFS is a graph traversal algorithm that explores all neighbors at the current depth before moving to nodes at the next depth level.

Core Steps:
Start from the root node.

Use a queue to keep track of the nodes to visit.

Mark each node as visited after it's dequeued.

For each visited node, enqueue all its unvisited neighbors.

Applications of BFS
Shortest path in unweighted graphs

Crawling websites (breadth-first crawling)

Social network analysis

Finding connected components

Peer-to-peer networks (e.g., BitTorrent)

Time & Space Complexity
Time Complexity:
O(V + E)
Where:

V = number of vertices

E = number of edges

Space Complexity:
O(V) for the visited array and queue

🧪 Sample Input & Output

![alt text](image-4.png)

The graph:

![alt text](images/BFS1.png)


