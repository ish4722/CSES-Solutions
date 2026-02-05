#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <deque>
#include <string>
#include <sstream>
#include <iomanip>
#include <chrono>
#include <random>
#include <cassert>
using namespace std;



void dfs(int node, int d, const vector<vector<int>>& adj, vector<int>& depth) {
    depth[node] = d;
    for (int child : adj[node]) {
        dfs(child, d + 1, adj, depth);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    const int LOG = 20;
    vector<vector<int>> up(n + 1, vector<int>(LOG));

    for (int i = 2; i <= n; i++) {
        cin >> up[i][0];
    }

    vector<vector<int>> adj(n + 1);
    for (int i = 2; i <= n; i++) {
        adj[up[i][0]].push_back(i);
    }
    vector<int> depth(n + 1);
    dfs(1,0,adj,depth);

    // Precompute ancestors
    for (int j = 1; j < LOG; j++) {
        for (int i = 1; i <= n; i++) {
            up[i][j] = up[ up[i][j - 1] ][j - 1];
        }
    }



    while (q--) {
        int u, v;
        cin >> u >> v;


        if (depth[u] < depth[v]) swap(u, v);
        int diff = depth[u] - depth[v];

        for (int j = 0; j < LOG; j++) {
            if (diff & (1 << j)) {
                u = up[u][j];
            }
        }
        if (u == v) {
        cout << u << "\n";
        continue;
    }

        for (int j = LOG - 1; j >= 0; j--) {
            if (up[u][j] != up[v][j]) {
                u = up[u][j];
                v = up[v][j];
            }
        }

        cout << up[u][0] << "\n";
    }
}