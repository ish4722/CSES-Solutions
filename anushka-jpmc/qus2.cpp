#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

/*
  This program simulates a contagion-style default propagation in a fixed
  directed financial network of 20 entities (nodes).

  Each directed edge carries an exposure value.
  Each node has a predefined default threshold.

  For each test case:
  - A set of initially defaulted nodes is given (Round 0).
  - In subsequent rounds, losses propagate through outgoing edges.
  - A node defaults if its accumulated loss meets or exceeds its threshold.
  - Defaults are printed round-by-round in sorted order.
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // ===== Fixed network definition (given in problem statement) =====
    vector<pair<int,int>> edges = {
        {7,19},{2,14},{0,2},{13,19},{4,13},{10,19},{6,8},{1,13},{5,17},{8,17},
        {3,8},{12,18},{4,16},{9,18},{0,7},{2,9},{7,13},{5,14},{10,16},{6,12},
        {1,8},{3,12},{0,12},{11,17},{13,15},{8,10},{4,6},{7,16},{2,4},{19,15},
        {5,7},{12,14},{0,9},{6,18},{1,10},{3,15},{11,13},{7,9},{10,12},{5,11},
        {8,14},{15,17},{14,16},{4,10},{16,15},{0,5},{2,11},{1,6},{9,11},{5,6},
        {3,5},{16,18}
    };

    // Exposure values corresponding to each directed edge
    vector<int> exposure = {
        20,40,35,60,60,35,60,35,30,30,
        45,25,25,25,25,30,30,70,45,25,
        20,45,30,30,40,40,80,55,70,50,
        55,70,45,35,50,30,55,45,60,65,
        65,35,50,35,50,60,65,55,35,20,
        20,45
    };

    // Default threshold for each node
    vector<int> threshold = {
        100,0,200,30,90,0,70,170,50,80,
        110,40,60,130,190,120,140,180,160,150
    };

    // Adjacency list storing (neighbor, exposure)
    vector<vector<pair<int,int>>> adj(20);
    for (int i = 0; i < edges.size(); i++) {
        adj[edges[i].first].push_back({edges[i].second, exposure[i]});
    }

    // ===== Input handling =====
    int T;
    cin >> T;   // Number of test cases

    while (T--) {
        int k;
        cin >> k;   // Number of initially defaulted nodes

        vector<int> init(k);
        for (int i = 0; i < k; i++) cin >> init[i];

        // Tracks whether a node has already defaulted
        vector<bool> defaulted(20, false);

        // Accumulated loss for each node
        vector<long long> loss(20, 0);

        // Stores defaulted nodes round-by-round
        vector<vector<int>> rounds;

        /*
          Round 0:
          - Initial defaults are given directly
          - Printed in sorted order
        */
        sort(init.begin(), init.end());
        rounds.push_back(init);
        for (int b : init) defaulted[b] = true;

        vector<int> prev = init;

        /*
          Subsequent rounds:
          - Loss propagates from nodes defaulted in the previous round
          - New defaults are identified by threshold comparison
        */
        while (true) {
            vector<int> cur;

            // Accumulate losses from previously defaulted nodes
            for (int u : prev) {
                for (auto [v, w] : adj[u]) {
                    if (!defaulted[v]) {
                        loss[v] += w;
                    }
                }
            }

            // Check which nodes newly cross their default thresholds
            for (int i = 0; i < 20; i++) {
                if (!defaulted[i] && loss[i] >= threshold[i]) {
                    cur.push_back(i);
                }
            }

            // Stop if no new defaults occur
            if (cur.empty()) break;

            sort(cur.begin(), cur.end());
            rounds.push_back(cur);

            for (int x : cur) defaulted[x] = true;
            prev = cur;
        }

        // ===== Output =====
        for (auto &r : rounds) {
            for (int i = 0; i < r.size(); i++) {
                if (i) cout << " ";
                cout << r[i];
            }
            cout << "\n";
        }

        // Blank line between test cases if required
        if (T) cout << "\n";
    }

    return 0;
}
