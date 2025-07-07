#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <climits>
#include <set>

using namespace std;

// A* Search Function
// Takes a graph (adjacency list), start and goal node, and heuristic values
vector<int> a_star_search(
    unordered_map<int, vector<pair<int, int>>> &graph,
    int start, int goal,
    unordered_map<int, int> &heuristic)
{

    // Priority queue element: pair of (f = g + h, path as vector)
    typedef pair<int, vector<int>> PQElement;

    // Min-heap priority queue based on f = g + h
    priority_queue<PQElement, vector<PQElement>, greater<PQElement>> pq;

    // Stores actual cost from start to each node (g value)
    unordered_map<int, int> g_values;
    g_values[start] = 0;

    // Initialize priority queue with start node
    pq.push(make_pair(heuristic[start], vector<int>{start}));

    // Visited set to prevent re-processing of the same node
    set<int> visited;

    // Main loop of A* algorithm
    while (!pq.empty())
    {
        PQElement top = pq.top();
        pq.pop();

        int f_val = top.first;
        vector<int> path = top.second;
        int current = path.back(); // Current node is last in path

        // Goal check
        if (current == goal)
        {
            return path;
        }

        // Skip if already visited
        if (visited.find(current) != visited.end())
        {
            continue;
        }
        visited.insert(current);

        // Explore neighbors of current node
        for (int i = 0; i < graph[current].size(); ++i)
        {
            int neighbor = graph[current][i].first;
            int cost = graph[current][i].second;

            // Calculate tentative g (cost so far to reach neighbor)
            int tentative_g = g_values[current] + cost;

            // If new g is better, or node is not visited yet
            if (g_values.find(neighbor) == g_values.end() || tentative_g < g_values[neighbor])
            {
                g_values[neighbor] = tentative_g;          // Update g value
                int f = tentative_g + heuristic[neighbor]; // f = g + h

                // Create new path including this neighbor
                vector<int> new_path = path;
                new_path.push_back(neighbor);

                // Push new path into priority queue
                pq.push(make_pair(f, new_path));
            }
        }
    }

    // Return empty path if goal is not reachable
    return {};
}

int main()
{
    unordered_map<int, vector<pair<int, int>>> graph; // Adjacency list: node -> list of (neighbor, cost)
    unordered_map<int, int> heuristic;                // Heuristic values: node -> heuristic estimate to goal
    int nodes, edges;

    // Input number of nodes
    cout << "Enter number of nodes: ";
    cin >> nodes;

    // Input heuristic value for each node
    cout << "Enter heuristic values for each node:" << endl;
    for (int i = 0; i < nodes; i++)
    {
        int node, h;
        cout << "Node " << i + 1 << ": ";
        cin >> node >> h;
        heuristic[node] = h;
    }

    // Input number of edges
    cout << "Enter number of edges: ";
    cin >> edges;

    // Ask if the graph is undirected
    cout << "Is the graph undirected? (1 for Yes, 0 for No): ";
    int undirected;
    cin >> undirected;

    // Input edge data: from, to, cost
    cout << "Enter edges with cost (format: from to cost):" << endl;
    for (int i = 0; i < edges; i++)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        graph[from].push_back(make_pair(to, cost));
        if (undirected)
        {
            graph[to].push_back(make_pair(from, cost));
        }
    }

    // Input start and goal nodes
    int start, goal;
    cout << "Enter start node: ";
    cin >> start;
    cout << "Enter goal node: ";
    cin >> goal;

    // Call A* search and get path
    vector<int> path = a_star_search(graph, start, goal, heuristic);

    // Output result
    if (path.empty())
    {
        cout << "No path found from " << start << " to " << goal << "!" << endl;
    }
    else
    {
        cout << "A* Path from " << start << " to " << goal << ": ";
        for (int i = 0; i < path.size(); i++)
        {
            cout << path[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
