 // Reconstruct path from destination to source :most imp learning
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <iomanip>

using namespace std;

/*
  This program finds the maximum probability path between two nodes
  in a fixed directed graph of 30 nodes.

  Each directed edge has an associated success probability.
  The goal is to compute:
  1) The maximum probability of reaching the destination from the source.
  2) One corresponding path that achieves this maximum probability.

  The algorithm used is a modified Dijkstra’s algorithm where:
  - Instead of minimizing distance, we maximize probability.
  - Path probability is computed as the product of edge probabilities.
*/

int main() {

    // ===== Fixed directed graph definition =====
    vector<pair<int,int>> edges = {
        {0,1},{1,2},{2,3},{3,4},{4,0},{2,5},{5,6},{6,2},{7,8},{8,9},
        {9,10},{10,7},{11,12},{12,13},{13,14},{14,11},{15,16},{16,17},
        {17,18},{18,15},{19,20},{20,21},{21,22},{22,19},{23,24},{24,25},
        {25,26},{26,23},{27,28},{28,29},{29,27},{4,7},{10,11},{14,15},
        {18,19},{22,23},{26,27},{6,8},{9,12},{13,16},{17,20},{21,24},
        {25,28},{1,15},{5,19},{8,23},{12,27},{16,0},{20,7},{24,11},
        {28,3},{0,29},{3,17},{7,21},{11,25},{15,4},{19,8},{23,12},{27,16}
    };

    // Probability values corresponding to each directed edge
    vector<double> probability = {
        0.81,0.93,0.67,0.61,0.77,0.77,0.89,0.77,0.77,0.67,
        0.95,0.44,0.44,0.41,0.95,0.41,0.54,0.44,0.38,0.44,
        0.38,0.41,0.95,0.41,0.95,0.41,0.54,0.44,0.38,0.44,
        0.38,0.41,0.95,0.41,0.95,0.41,0.54,0.44,0.38,0.44,
        0.38,0.41,0.95,0.41,0.95,0.41,0.54,0.44,0.38,0.44,
        0.38,0.41,0.95,0.41,0.95,0.41,0.54,0.44,0.74
    };

    // Adjacency list storing (neighbor, edge probability)
    vector<vector<pair<int,double>>> adj(30);
    for (int i = 0; i < edges.size(); i++) {
        adj[edges[i].first].push_back({edges[i].second, probability[i]});
    }

    // ===== Input =====
    int T;
    cin >> T;   // Number of test cases

    while (T--) {
        int start, end;
        cin >> start >> end;

        // Stores maximum probability to reach each node
        vector<double> maxProb(30, 0.0);

        // Parent array used for path reconstruction
        vector<int> parent(30, -1);

        // Max-heap priority queue based on probability
        priority_queue<pair<double,int>> pq;

        // Initialization
        maxProb[start] = 1.0;
        pq.push({1.0, start});

        /*
          Modified Dijkstra's algorithm:
          - Always expand the node with the current highest probability
          - Update neighbors if a better probability path is found
        */
        while (!pq.empty()) {
            auto [prob, u] = pq.top();
            pq.pop();

            if (prob < maxProb[u]) continue;

            for (auto &[v, p] : adj[u]) {
                double newProb = prob * p;
                if (newProb > maxProb[v]) {
                    maxProb[v] = newProb;
                    parent[v] = u;
                    pq.push({newProb, v});
                }
            }
        }

        // If destination is unreachable
        if (maxProb[end] == 0.0) {
            cout << fixed << setprecision(6) << 0.000000 << "\n\n";
            continue;
        }

        // Output maximum probability
        cout << fixed << setprecision(6) << maxProb[end] << "\n";

       
       

        vector<int> path;
        for (int v = end; v != -1; v = parent[v])
            path.push_back(v);

        reverse(path.begin(), path.end());

        // Output path
        for (int x : path) cout << x << " ";
        cout << "\n\n";
    }

    return 0;
}
