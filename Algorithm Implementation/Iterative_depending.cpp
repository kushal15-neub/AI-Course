#include <iostream>
#include <vector>
using namespace std;

// Depth-Limited Search (DLS)
// graph: adjacency list representation of graph
// src: current node
// goal: target node
// limit: current depth limit
// visited: keeps track of visited nodes to avoid cycles in current iteration
bool DLS(vector<vector<int>> &graph, int src, int goal, int limit, vector<bool> &visited)
{
    if (src == goal) // Goal test
        return true;

    if (limit <= 0) // Depth limit reached, stop going deeper
        return false;

    visited[src] = true; // Mark current node visited

    // Explore neighbors within the depth limit
    for (int neighbor : graph[src])
    {
        if (!visited[neighbor]) // Avoid revisiting in current path
        {
            // Recurse deeper with reduced depth limit
            if (DLS(graph, neighbor, goal, limit - 1, visited))
                return true; // Goal found in deeper subtree
        }
    }

    return false; // Goal not found within this depth
}

// Iterative Deepening Search (IDS)
// Calls DLS repeatedly with increasing depth limits until goal found or max_depth reached
bool IDS(vector<vector<int>> &graph, int src, int goal, int max_depth)
{
    for (int depth = 0; depth <= max_depth; ++depth)
    {
        vector<bool> visited(graph.size(), false); // Reset visited for each depth iteration

        if (DLS(graph, src, goal, depth, visited))
        {
            cout << "Goal found at depth " << depth << endl;
            return true; // Goal found, stop search
        }
    }
    return false; // Goal not found within max_depth
}

int main()
{
    int n, e;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> e;

    vector<vector<int>> graph(n);

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < e; ++i)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v); // Directed edge from u to v
    }

    int start, goal;
    cout << "Enter start and goal node: ";
    cin >> start >> goal;

    int max_depth = 10; // Maximum depth to limit search
    if (!IDS(graph, start, goal, max_depth))
    {
        cout << "Goal not found up to depth " << max_depth << endl;
    }

    return 0;
}
