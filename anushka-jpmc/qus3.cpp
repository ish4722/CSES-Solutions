#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

static const int N = 20;

vector<pair<int,int>> revAdj[N];

int dp[N];       
bool vis[N];     

int dfs(int v) {

    if (vis[v]) return dp[v]; //if already computed we can return the value

    vis[v] = true;

    int best = 0;  

    // Explore all incoming edges
    for (auto &e : revAdj[v]) {
        int u = e.first;
        int w = e.second;
        best = max(best, dfs(u) + w);
    }

    dp[v] = best;
    return dp[v];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    vector<pair<int,int>> edges = {
        {7,19},{2,14},{0,2},{13,19},{4,13},{10,19},{6,8},{1,13},{5,17},{8,17},
        {3,8},{12,18},{4,16},{9,18},{0,7},{2,9},{7,13},{5,14},{10,16},{6,12},
        {1,8},{3,12},{0,12},{11,17},{13,15},{8,10},{4,6},{7,16},{2,4},{9,15},
        {5,7},{12,14},{0,9},{6,18},{1,10},{3,5},{11,13},{7,9},{10,12},{5,11},
        {8,14},{15,17},{14,16},{4,10},{6,15},{0,5},{2,11},{7,6},{9,11},{5,6},
        {3,5},{16,18}
    };

    vector<int> exposure = {
        20,40,35,60,60,35,60,35,30,30,
        45,25,25,25,25,30,30,70,45,25,
        20,45,30,30,40,40,80,55,70,50,
        55,70,45,35,50,30,55,45,60,65,
        65,35,50,35,50,60,65,55,35,20,
        20,45
    };

// reversed the graph so that we can track dependencies easily
    for (int i = 0; i < (int)edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;
        int w = exposure[i];
        revAdj[v].push_back({u, w});
    }

    // Initialize DP and visited arrays
    memset(vis, false, sizeof(vis));
    memset(dp, 0, sizeof(dp));

    // Compute maximum exposure for every node
    for (int i = 0; i < N; i++) {
        dfs(i);
    }

    // Output results
    for (int i = 0; i < N; i++) {
        cout << dp[i];
        if (i + 1 < N) cout << " ";
    }
    cout << "\n";

    return 0;
}

/*
The problem can be reframed as:
"If I am a particular bank, where can my losses actually come from?"


The network is directed, and every edge represents a possible transfer of
exposure. 

For any bank X, the total exposure depends on:
- All banks that directly lend to X
- Plus whatever exposure those banks themselves receive

So the problem naturally becomes:
"Find the maximum-weight path ending at each node."



The input gives edges in the form (u → v), meaning u lends to v.

But to compute exposure at v, we need quick access to:
"Which banks lend to v?"

Therefore, the first practical step was to reverse all edges and build
a reverse adjacency list:
    v → {u, weight}

This makes dependency tracking straightforward.


Once the reversed graph is built, the logic becomes simple:

To compute exposure at bank v:
- Look at all banks u that lend to v
- For each u, exposure is:
      exposure(u) + weight(u → v)
- Take the maximum among all such possibilities

This leads naturally to a recursive DFS formulation.

*/
