Beam Search Algorithm

 How the Algorithm Works:
Beam Search is a heuristic-based search algorithm. It's like Breadth-First Search, but at each level of the tree or graph, it only keeps the best k nodes (beam width) based on a heuristic function.

Core Steps:
Start from the root node.

Expand all children of the current level's nodes.

Rank children using their heuristic value (lower is better).

Keep only the top beam_width children.

Repeat the process until the goal is found or no nodes remain.


 Applications of Beam Search:
Natural Language Processing (e.g., Machine Translation, Speech Recognition)

AI Planning and decision-making

Game playing AI where approximate best paths are enough

Search engines for ranking a limited number of results

 Time & Space Complexity:
Time Complexity:
O(b \* d)
Where:

b = beam width

d = depth to the goal node

Space Complexity:
O(b) (keeps only the best b nodes per level)

 Sample Input & Output

![alt text](images/beam1.png)

The graph:

![alt text](images/beam.png)

