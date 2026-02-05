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




// void dfs(int node, int d, const vector<vector<int>>& adj, vector<int>& depth) {
//     depth[node] = d;
//     for (int child : adj[node]) {
//         dfs(child, d + 1, adj, depth);
//     }
// }


// int main(){
//     int n, q;
//     cin >> n >> q;

//     vector<int> parent(n + 1);
//     for (int i = 2; i <= n; i++) {
//         cin >> parent[i];
//     }
//     vector<vector<int>> adj(n + 1);
//     for (int i = 2; i <= n; i++) {
//         adj[parent[i]].push_back(i);
//     }
//     vector<int> depth(n + 1);
//     dfs(1,0,adj,depth);

//     for(int i=0;i<q;i++){
//         int u, k;
//         cin >> u >> k;
//         if (depth[u] < k) {
//             cout << -1 << "\n";
//             continue;
//         }
//         for (int i = 0; i < k; i++) {
//             u = parent[u];
//         }
//         cout << u << "\n";
//     }

// }
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

    // Precompute ancestors
    for (int j = 1; j < LOG; j++) {
        for (int i = 1; i <= n; i++) {
            up[i][j] = up[ up[i][j - 1] ][j - 1];
        }
    }

    while (q--) {
        int x, k;
        cin >> x >> k;

        for (int j = 0; j < LOG; j++) {
            if (k & (1 << j)) {
                x = up[x][j];
                if (x == 0) break;
            }
        }

        cout << (x == 0 ? -1 : x) << "\n";
    }
}