#include <bits/stdc++.h>
using namespace std;

int adj[1000][1000]; // Adjacency matrix to store edges

// Breadth-First Search function
void bfs(int no_vertices, int root)
{
    int visited[no_vertices]; // To track visited nodes
    queue<int> q;             // Queue for BFS traversal

    // Initialize all nodes as unvisited
    for (int i = 0; i < no_vertices; ++i)
    {
        visited[i] = 0;
    }

    // Start from root
    q.push(root);
    visited[root] = 1;

    cout << "BFS traversal starting from node " << root << ": ";

    // BFS Loop
    while (!q.empty())
    {
        int s = q.front(); // Current node
        q.pop();
        cout << s << " "; // Print visited node

        // Explore all neighbors of s
        for (int i = 0; i < no_vertices; ++i)
        {
            // If edge exists and node i is unvisited
            if (adj[s][i] == 1 && visited[i] == 0)
            {
                q.push(i);
                visited[i] = 1;
            }
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

    // Initialize adjacency matrix to 0
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            adj[i][j] = 0;
        }
    }

    // Input edges
    cout << "Enter the edges (format: u v):\n";
    for (int i = 0; i < E; i++)
    {
        int node1, node2;
        cin >> node1 >> node2;

        adj[node1][node2] = 1;
        adj[node2][node1] = 1; // Since it's an undirected graph
    }

    // Input root node for BFS
    int root;
    cout << "Enter the root node to start BFS: ";
    cin >> root;

    bfs(V, root);

    return 0;
}
