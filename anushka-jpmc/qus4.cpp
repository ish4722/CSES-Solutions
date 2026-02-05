#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// direct qus of toposort

int main() {

    // ===== Fixed directed graph definition =====
    // Each edge u -> v means: Bank u owes Bank v
    vector<pair<int, int>> edges = {
        {7, 19}, {2, 14}, {0, 2}, {13, 19}, {4, 13}, {10, 19}, {6, 8}, {1, 13},
        {5, 17}, {8, 17}, {3, 8}, {12, 18}, {4, 16}, {9, 18}, {0, 7}, {2, 9},
        {7, 13}, {5, 14}, {10, 16}, {6, 12}, {1, 6}, {3, 12}, {0, 12},
        {11, 17}, {13, 15}, {8, 10}, {4, 6}, {7, 16}, {2, 4}, {9, 15},
        {5, 7}, {12, 14}, {0, 9}, {6, 18}, {1, 10}, {3, 15}, {11, 13},
        {7, 9}, {10, 12}, {5, 11}, {8, 14}, {15, 17}, {14, 16}, {4, 10},
        {6, 15}, {0, 5}, {2, 11}, {1, 6}, {9, 11}, {5, 6}, {3, 5}, {16, 18}
    };

    int num_banks = 20;

    /*
      Adjacency list representation:
      adj[u] contains all banks v such that u -> v (u owes v)

      indegree[v] counts how many banks still owe money to v
    */
    vector<vector<int>> adj(num_banks);
    vector<int> indegree(num_banks, 0);

    // Build graph and indegree array
    for (auto& edge : edges) {
        int u = edge.first;
        int v = edge.second;
        adj[u].push_back(v);
        indegree[v]++;
    }

    /*
      Kahn’s Algorithm for Topological Sorting:

      Banks with indegree 0 have no remaining dependencies
      and can safely appear next in the default order.
    */
    queue<int> q;

    // Initialize queue with banks having no dependencies
    for (int i = 0; i < num_banks; ++i) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> default_order;

    // Process banks in dependency-respecting order
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        default_order.push_back(u);

        // Simulate default of bank u by removing its outgoing edges
        for (int v : adj[u]) {
            indegree[v]--;
            if (indegree[v] == 0) {
                q.push(v);
            }
        }
    }

    /*
      If all banks are processed, a valid topological order exists.
      Otherwise, a cycle would exist (not expected in this problem).
    */
    if (default_order.size() == num_banks) {
        for (int i = 0; i < num_banks; ++i) {
            cout << default_order[i];
            if (i + 1 < num_banks) cout << " ";
        }
        cout << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
