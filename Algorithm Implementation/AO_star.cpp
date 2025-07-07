#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <limits>
#include <set>

using namespace std;

const int INF = 1e9;

struct Child
{
    vector<string> nodes; // list of children (OR = 1 child, AND = multiple)
    int cost;             // cost to go through this branch
};

// Graph and Heuristic map
unordered_map<string, vector<Child>> graph;
unordered_map<string, int> heuristic;
unordered_map<string, vector<string>> solution_path;
set<string> visited;

// AO* core function
int AOStar(string node, bool backtrack = false)
{
    if (heuristic[node] == 0)
        return 0; // goal node

    if (visited.find(node) != visited.end() && !backtrack)
        return heuristic[node];

    visited.insert(node);

    int min_cost = INF;
    vector<string> best_path;

    for (auto child : graph[node])
    {
        int current_cost = child.cost;
        vector<string> sub_path;

        // Add cost of all subnodes
        for (auto subnode : child.nodes)
        {
            current_cost += AOStar(subnode, true);
            sub_path.push_back(subnode);
        }

        if (current_cost < min_cost)
        {
            min_cost = current_cost;
            best_path = sub_path;
        }
    }

    heuristic[node] = min_cost;
    solution_path[node] = best_path;

    if (!backtrack)
    {
        for (auto child : solution_path[node])
        {
            AOStar(child); // expand best children
        }
    }

    return heuristic[node];
}

// Function to print solution path
void print_solution(string node)
{
    cout << node;
    if (solution_path.find(node) == solution_path.end())
        return;

    vector<string> path = solution_path[node];
    for (auto child : path)
    {
        cout << " -> ";
        print_solution(child);
    }
}

int main()
{
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter node names and their heuristic values:\n";
    for (int i = 0; i < n; ++i)
    {
        string node;
        int h;
        cin >> node >> h;
        heuristic[node] = h;
    }

    int edges;
    cout << "Enter number of edges (branches): ";
    cin >> edges;
    cin.ignore();

    /*
      Input format for each branch:
      parent type cost child1 child2 ...

      Example (OR):
      A OR 3 B     => A -> B with cost 3

      Example (AND):
      A AND 6 C D  => A -> C and D (both must be solved) with cost 6
    */

    cout << "\nEnter branches in the format: parent [AND/OR] cost child1 [child2...]\n";
    for (int i = 0; i < edges; ++i)
    {
        string parent, type;
        int cost;
        cout << "Branch " << i + 1 << ": ";
        cin >> parent >> type >> cost;

        vector<string> children;
        string child;
        while (cin.peek() != '\n' && cin >> child)
        {
            children.push_back(child);
        }
        cin.ignore(); // clear newline

        if (type == "OR" && children.size() > 1)
        {
            cout << "OR branch should have only one child. Invalid input.\n";
            return 1;
        }

        graph[parent].push_back({children, cost});
    }

    string start;
    cout << "\nEnter start node: ";
    cin >> start;

    AOStar(start);

    cout << "\nOptimal AO* Path:\n";
    print_solution(start);
    cout << endl;

    return 0;
}
