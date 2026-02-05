#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

/*
  This program simulates information propagation over a fixed directed network
  consisting of 20 nodes (0 to 19).

  For each test case:
  - A set of initial active nodes is provided.
  - Using Breadth First Search (BFS), the program prints nodes activated
    round-by-round.
  - Nodes already visited are not processed again.
  - Each round’s output is printed in sorted order as per problem requirement.
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Fixed directed edges of the network (as given in the problem statement)
    vector<pair<int,int>> edges = {
        {7,19},{2,14},{0,2},{13,19},{4,13},{10,19},{6,8},{1,13},{5,17},{8,17},
        {3,8},{12,18},{4,16},{9,18},{0,7},{2,9},{7,13},{5,14},{10,16},{6,12},
        {1,8},{3,12},{0,12},{11,17},{13,15},{8,10},{4,6},{7,16},{2,4},{19,15},
        {5,7},{12,14},{0,9},{6,18},{1,10},{3,15},{11,13},{7,9},{10,12},{5,11},
        {8,14},{15,17},{14,16},{4,10},{6,15},{0,5},{2,11},{1,6},{9,11},{5,6},
        {3,5},{16,18}
    };

    // Adjacency list representation of the network
    vector<vector<int>> adj(20);
    for (auto &e : edges) {
        adj[e.first].push_back(e.second);
    }

    int T;
    cin >> T;   // Number of test cases

    while (T--) {
        int k;
        cin >> k;   // Number of initially active nodes

        vector<int> initial(k);
        for (int i = 0; i < k; i++) {
            cin >> initial[i];
        }

        // Visited array ensures each node is processed only once
        vector<bool> visited(20, false);

        // Queue used for BFS traversal
        queue<int> q;

        /*
          Round 0:
          - Initial active nodes are marked visited
          - Printed in sorted order
        */
        sort(initial.begin(), initial.end());
        for (int x : initial) {
            if (!visited[x]) {
                visited[x] = true;
                q.push(x);
            }
        }

        // Output for round 0
        for (int i = 0; i < initial.size(); i++) {
            if (i) cout << " ";
            cout << initial[i];
        }
        cout << "\n";

        /*
          BFS expansion:
          - Each BFS level corresponds to one propagation round
          - Newly discovered nodes form the next round
        */
        while (!q.empty()) {
            int sz = q.size();
            vector<int> nextRound;

            // Process current round
            while (sz--) {
                int u = q.front();
                q.pop();

                for (int v : adj[u]) {
                    if (!visited[v]) {
                        visited[v] = true;
                        nextRound.push_back(v);
                    }
                }
            }

            // Stop if no new nodes are activated
            if (nextRound.empty()) break;


            // Output next round in sorted order
            sort(nextRound.begin(), nextRound.end());
            for (int i = 0; i < nextRound.size(); i++) {
                if (i) cout << " ";
                cout << nextRound[i];
                q.push(nextRound[i]);
            }
            cout << "\n";
        }

        // Blank line between test cases (only if more remain)
        if (T) cout << "\n";
    }

    return 0;
}
