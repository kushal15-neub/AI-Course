#include <bits/stdc++.h>
using namespace std;

// Function to evaluate the score at a given leaf node index
int evaluate(int index, const vector<int> &scores)
{
    return scores[index];
}

// Alpha-Beta Pruning function
int alpha_beta(int depth, int node_index, bool is_max,
               const vector<int> &scores, int h,
               int alpha, int beta)
{
    // Base case: if we've reached the maximum depth (leaf nodes)
    if (depth == h)
    {
        return evaluate(node_index, scores);
    }

    // If it's the maximizer's turn
    if (is_max)
    {
        int best = INT_MIN;
        // Explore all possible moves (2 children in binary tree)
        for (int i = 0; i < 2; i++)
        {
            int val = alpha_beta(depth + 1, node_index * 2 + i, false, scores, h, alpha, beta);
            best = max(best, val);
            alpha = max(alpha, best);
            // Alpha-Beta pruning
            if (beta <= alpha)
                break; // Beta cut-off
        }
        return best;
    }
    // If it's the minimizer's turn
    else
    {
        int best = INT_MAX;
        // Explore all possible moves (2 children in binary tree)
        for (int i = 0; i < 2; i++)
        {
            int val = alpha_beta(depth + 1, node_index * 2 + i, true, scores, h, alpha, beta);
            best = min(best, val);
            beta = min(beta, best);
            // Alpha-Beta pruning
            if (beta <= alpha)
                break; // Alpha cut-off
        }
        return best;
    }
}

int main()
{
    int num_leaves;
    cout << "Enter the number of leaf nodes (must be a power of 2): ";
    cin >> num_leaves;

    // Validate input is a power of 2
    if ((num_leaves & (num_leaves - 1)) != 0)
    {
        cout << "Error: Number of leaves must be a power of 2 for a binary tree." << endl;
        return 1;
    }

    vector<int> scores(num_leaves);
    cout << "Enter the " << num_leaves << " leaf node scores:" << endl;
    for (int i = 0; i < num_leaves; i++)
    {
        cout << "Score " << i + 1 << ": ";
        cin >> scores[i];
    }

    // Calculate tree height (number of levels)
    int h = log2(num_leaves);

    // Start the Alpha-Beta Pruning from the root
    int result = alpha_beta(0, 0, true, scores, h, INT_MIN, INT_MAX);
    cout << "Optimal value: " << result << endl;

    return 0;
}