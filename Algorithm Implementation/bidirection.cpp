#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

// Bidirectional BFS Function
bool bidirectional_search(vector<vector<int>> &graph, int start, int goal)
{
    unordered_set<int> visited_f, visited_b; // Visited sets for forward and backward searches
    queue<int> q_f, q_b;                     // Queues for forward and backward BFS

    // Initialize
    q_f.push(start);
    q_b.push(goal);
    visited_f.insert(start);
    visited_b.insert(goal);

    // Run BFS until either queue is empty
    while (!q_f.empty() && !q_b.empty())
    {
        int f = q_f.front(); // Current node from forward search
        q_f.pop();
        int b = q_b.front(); // Current node from backward search
        q_b.pop();

        // If frontiers meet, path exists
        if (visited_b.count(f) || visited_f.count(b))
        {
            cout << "Path found (meeting point at node " << (visited_b.count(f) ? f : b) << ")\n";
            return true;
        }

        // Expand forward frontier
        for (int neighbor : graph[f])
        {
            if (!visited_f.count(neighbor))
            {
                visited_f.insert(neighbor);
                q_f.push(neighbor);
            }
        }

        // Expand backward frontier
        for (int neighbor : graph[b])
        {
            if (!visited_b.count(neighbor))
            {
                visited_b.insert(neighbor);
                q_b.push(neighbor);
            }
        }
    }

    // If queues are empty and no intersection
    return false;
}

int main()
{
    int n, e;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> e;

    vector<vector<int>> graph(n); // Adjacency list

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < e; ++i)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); // Because the graph is undirected
    }

    int start, goal;
    cout << "Enter start and goal nodes: ";
    cin >> start >> goal;

    if (!bidirectional_search(graph, start, goal))
    {
        cout << "No path found.\n";
    }

    return 0;
}
