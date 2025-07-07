#include <bits/stdc++.h>
using namespace std;

// Node class: Represents a neighbor in the graph
class Node
{
public:
    int v, weight;
    Node(int V, int Weight)
    {
        v = V;
        weight = Weight;
    }
};

// pathNode class: Helps reconstruct the final path from src to dest
class pathNode
{
public:
    int node;
    pathNode *parent;

    pathNode(int Node)
    {
        node = Node;
        parent = NULL;
    }

    pathNode(int Node, pathNode *Parent)
    {
        node = Node;
        parent = Parent;
    }
};

// Adjacency list to represent the graph
static vector<vector<Node *>> adj;

// Add an edge to the graph (directed)
void addEdge(int u, int v, int weight)
{
    adj[u].push_back(new Node(v, weight));
}

// Greedy Best-First Search function
// Uses heuristic values (h[]) to explore nodes that "look" closer to goal
vector<int> GBFS(int h[], int V, int src, int dest)
{
    vector<pathNode *> openList;  // Nodes to be explored
    vector<pathNode *> closeList; // Nodes already explored

    openList.push_back(new pathNode(src)); // Start with source node

    while (!openList.empty())
    {
        pathNode *currentNode = openList[0];
        int currentIndex = 0;

        // Select node with the smallest heuristic (greedy step)
        for (int i = 0; i < openList.size(); i++)
        {
            if (h[openList[i]->node] < h[currentNode->node])
            {
                currentNode = openList[i];
                currentIndex = i;
            }
        }

        // Remove current from openList, add to closeList
        openList.erase(openList.begin() + currentIndex);
        closeList.push_back(currentNode);

        // If goal found, build path using parent pointers
        if (currentNode->node == dest)
        {
            vector<int> path;
            pathNode *cur = currentNode;
            while (cur != NULL)
            {
                path.push_back(cur->node);
                cur = cur->parent;
            }
            reverse(path.begin(), path.end());
            return path;
        }

        // Expand neighbors of current node
        for (Node *neighbor : adj[currentNode->node])
        {
            bool foundInOpenList = false, foundInCloseList = false;

            // Check if already in openList
            for (pathNode *x : openList)
            {
                if (x->node == neighbor->v)
                {
                    foundInOpenList = true;
                    break;
                }
            }

            // Check if already in closeList
            for (pathNode *x : closeList)
            {
                if (x->node == neighbor->v)
                {
                    foundInCloseList = true;
                    break;
                }
            }

            // If not visited, add to openList with parent as currentNode
            if (!foundInOpenList && !foundInCloseList)
            {
                openList.push_back(new pathNode(neighbor->v, currentNode));
            }
        }
    }

    // Return empty vector if path not found
    return vector<int>();
}

int main()
{
    int V, E;

    cout << "Enter the number of vertices: ";
    cin >> V;

    adj.resize(V); // Resize the graph

    cout << "Enter the number of edges: ";
    cin >> E;

    cout << "Enter the edges (u v weight) one by one:\n";
    for (int i = 0; i < E; i++)
    {
        int u, v, weight;
        cin >> u >> v >> weight;
        addEdge(u, v, weight);
    }

    // Input heuristic values
    int h[V];
    cout << "Enter the heuristic values for each vertex:\n";
    for (int i = 0; i < V; i++)
    {
        cin >> h[i];
    }

    int src, dest;
    cout << "Enter the source node: ";
    cin >> src;
    cout << "Enter the destination node: ";
    cin >> dest;

    // Run GBFS
    vector<int> path = GBFS(h, V, src, dest);

    // Output result
    if (path.empty())
    {
        cout << "No path found from " << src << " to " << dest << endl;
    }
    else
    {
        cout << "Path from " << src << " to " << dest << ": ";
        for (int i = 0; i < path.size() - 1; i++)
        {
            cout << path[i] << " --> ";
        }
        cout << path.back() << endl;
    }

    return 0;
}
