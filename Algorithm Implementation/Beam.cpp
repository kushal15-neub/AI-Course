#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    int n, e;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> e;

    vector<int> heuristic(n);     // Heuristic values for each node
    vector<vector<int>> graph(n); // Adjacency list representation of graph

    // Input heuristic values for all nodes
    cout << "Enter heuristic values:\n";
    for (int i = 0; i < n; ++i)
    {
        cin >> heuristic[i];
    }

    // Input edges: each edge from u to v
    cout << "Enter edges (u v):\n";
    for (int i = 0; i < e; ++i)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    // Input starting node, goal node, and beam width
    int start, goal, beam_width;
    cout << "Enter start, goal, and beam width: ";
    cin >> start >> goal >> beam_width;

    queue<int> q;
    q.push(start); // Start search from the start node

    while (!q.empty())
    {
        vector<int> next_level; // Stores next-level candidate nodes

        // Process all nodes in current level
        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            // Goal test
            if (node == goal)
            {
                cout << "Goal found at node " << node << endl;
                return 0;
            }

            // Add all children of current node to next level
            next_level.insert(next_level.end(), graph[node].begin(), graph[node].end());
        }

        // Sort next level nodes by ascending heuristic values (smaller is better)
        sort(next_level.begin(), next_level.end(), [&](int a, int b)
             { return heuristic[a] < heuristic[b]; });

        // Clear the queue and push only top beam_width nodes
        q = queue<int>();
        for (int i = 0; i < min(beam_width, (int)next_level.size()); ++i)
        {
            q.push(next_level[i]);
        }
    }

    // If loop exits, goal not found
    cout << "Goal not found within beam width.\n";
    return 0;
}
