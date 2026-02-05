/*Use DFS twice → find diameter endpoints A and B
Distance from any node to farthest node =
max(distance to A, distance to B
good qus*/



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

#define int long long

vector<vector<int>> adj;
vector<int> used;
vector<int> distA, distB;

int ans = -1;
int far_node = 1;

void dfs_far(int u, int parent, int dist) {
    if (dist > ans) {
        ans = dist;
        far_node = u;
    }
    for (int v : adj[u]) {
        if (v == parent) continue;
        dfs_far(v, u, dist + 1);
    }
}

void dfs_dist(int u, int parent, int dist, vector<int>& d) {
    d[u] = dist;
    for (int v : adj[u]) {
        if (v == parent) continue;
        dfs_dist(v, u, dist + 1, d);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    adj.resize(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // Find A
    ans = -1;
    dfs_far(1, 0, 0);
    int A = far_node;

    // Find B
    ans = -1;
    dfs_far(A, 0, 0);
    int B = far_node;

    // Distances from A and B
    distA.assign(n + 1, 0);
    distB.assign(n + 1, 0);

    dfs_dist(A, 0, 0, distA);
    dfs_dist(B, 0, 0, distB);

    // Output result
    for (int i = 1; i <= n; i++) {
        cout << max(distA[i], distB[i]) << " ";
    }
    cout << "\n";

    return 0;
}
