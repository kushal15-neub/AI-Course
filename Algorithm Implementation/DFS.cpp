#include <iostream>
using namespace std;

const int maxi = 1000; // Maximum number of vertices
int adj[maxi][maxi];   // Adjacency matrix
bool visited[maxi];    // Visited array to mark visited nodes

// Depth-First Search Function
void dfs(int V, int root)
{
    visited[root] = true; // Mark current node as visited
    cout << root << " ";  // Print current node

    // Explore all unvisited neighbors
    for (int i = 0; i < V; ++i)
    {
        if (adj[root][i] == 1 && !visited[i])
        {
            dfs(V, i); // Recursive DFS call
        }
    }
}

int main()
{
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;

    cout << "Enter the number of edges: ";
    cin >> E;

    // Initialize adjacency matrix to 0 (no edges)
    for (int i = 0; i < V; ++i)
    {
        for (int j = 0; j < V; ++j)
        {
            adj[i][j] = 0;
        }
    }

    // Input the edges
    cout << "Enter the edges (node1 node2):\n";
    for (int i = 0; i < E; ++i)
    {
        int node1, node2;
        cin >> node1 >> node2;
        adj[node1][node2] = 1;
        adj[node2][node1] = 1; // Since the graph is undirected
    }

    // Initialize all nodes as unvisited
    for (int i = 0; i < V; ++i)
    {
        visited[i] = false;
    }

    // Input the starting node
    int root;
    cout << "Enter the root node: ";
    cin >> root;

    // Start DFS from the root node
    cout << "DFS traversal starting from node " << root << ": ";
    dfs(V, root);
    cout << endl;

    return 0;
}
