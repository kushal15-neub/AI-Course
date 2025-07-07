#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

// Evaluate the score of a leaf node at given index
int evaluate(int node_index, const vector<int> &scores)
{
    return scores[node_index];
}

// Minimax recursive function
// depth: current depth in the tree (root is 0)
// node_index: index of current node in the conceptual binary tree
// is_max: true if current player is MAX, false if MIN
// scores: leaf node values at maximum depth h
// h: total height of the tree (max depth)
int minimax(int depth, int node_index, bool is_max,
            const vector<int> &scores, int h)
{
    // If leaf node, return its score
    if (depth == h)
    {
        return evaluate(node_index, scores);
    }

    if (is_max)
    {
        // MAX player chooses the maximum value of children
        return max(minimax(depth + 1, node_index * 2, false, scores, h),
                   minimax(depth + 1, node_index * 2 + 1, false, scores, h));
    }
    else
    {
        // MIN player chooses the minimum value of children
        return min(minimax(depth + 1, node_index * 2, true, scores, h),
                   minimax(depth + 1, node_index * 2 + 1, true, scores, h));
    }
}

int main()
{
    int h;
    cout << "Enter height of the game tree: ";
    cin >> h;

    // Number of leaf nodes in a complete binary tree of height h
    int leaf_nodes = 1 << h;

    vector<int> scores(leaf_nodes);

    cout << "Enter " << leaf_nodes << " leaf node values:" << endl;
    for (int i = 0; i < leaf_nodes; i++)
    {
        cin >> scores[i];
    }

    // Call minimax from root (depth=0, node_index=0), MAX starts first
    int result = minimax(0, 0, true, scores, h);
    cout << "Optimal value: " << result << endl;

    return 0;
}
