#include <iostream>
#include <vector>
using namespace std;

// Recursive DLS function
bool DLS(const vector<vector<int>> &graph, int current, int goal, int limit, vector<bool> &visited)
{
    // Goal test
    if (current == goal)
    {
        cout << "Goal found at node: " << current << "\n";
        return true;
    }

    // Stop if depth limit reached
    if (limit == 0)
        return false;

    visited[current] = true;

    // Recur for all unvisited neighbors
    for (int neighbor : graph[current])
    {
        if (!visited[neighbor])
        {
            // Recur with decreased depth limit
            if (DLS(graph, neighbor, goal, limit - 1, visited))
                return true;
        }
    }

    return false; // Goal not found within this path
}

int main()
{
    int n, e;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> e;

    vector<vector<int>> graph(n); // Adjacency list

    // Input edges
    cout << "Enter edges (u v):\n";
    for (int i = 0; i < e; ++i)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v); // Directed edge from u to v
    }

    int start, goal, limit;
    cout << "Enter start, goal, and depth limit: ";
    cin >> start >> goal >> limit;

    vector<bool> visited(n, false); // Visited array to avoid cycles

    // Perform DLS
    if (!DLS(graph, start, goal, limit, visited))
        cout << "Goal not reachable within depth limit.\n";

    return 0;
}
