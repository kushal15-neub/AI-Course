#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

// Node structure holding node id, heuristic value, and neighbors
struct Node
{
    int id;
    int heuristic;
    vector<int> neighbors;
};

int main()
{
    int n, e;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> e;

    vector<Node> graph(n);

    // Input heuristic values for each node
    cout << "Enter heuristic values for each node:\n";
    for (int i = 0; i < n; ++i)
    {
        cout << "Heuristic[" << i << "]: ";
        cin >> graph[i].heuristic;
        graph[i].id = i;
    }

    // Input edges (undirected graph)
    cout << "Enter edges (u v):\n";
    for (int i = 0; i < e; ++i)
    {
        int u, v;
        cin >> u >> v;
        graph[u].neighbors.push_back(v);
        graph[v].neighbors.push_back(u); // add reverse edge for undirected graph
    }

    int start, goal;
    cout << "Enter start and goal nodes: ";
    cin >> start >> goal;

    // Priority queue stores pairs (heuristic value, node id)
    // Uses min-heap to pick node with smallest heuristic first
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<bool> visited(n, false); // Track visited nodes to avoid revisiting
    vector<int> parent(n, -1);      // To reconstruct the path

    // Push start node into priority queue
    pq.push({graph[start].heuristic, start});

    while (!pq.empty())
    {
        pair<int, int> top = pq.top();
        pq.pop();

        int h = top.first;        // heuristic value (not actually used further here)
        int current = top.second; // current node id

        if (visited[current])
            continue; // skip if already visited

        visited[current] = true; // mark as visited

        // Check if goal node is reached
        if (current == goal)
        {
            cout << "Goal found!\n";

            // Reconstruct path by following parents from goal to start
            stack<int> path;
            for (int at = goal; at != -1; at = parent[at])
                path.push(at);

            cout << "Path: ";
            while (!path.empty())
            {
                cout << path.top() << " ";
                path.pop();
            }
            cout << "\n";
            return 0;
        }

        // For each neighbor of current node
        for (int nbr : graph[current].neighbors)
        {
            if (!visited[nbr])
            {
                pq.push({graph[nbr].heuristic, nbr}); // add neighbor with heuristic priority
                parent[nbr] = current;                // remember parent for path reconstruction
            }
        }
    }

    // If goal was never reached
    cout << "Goal not reachable from start node.\n";
    return 0;
}
