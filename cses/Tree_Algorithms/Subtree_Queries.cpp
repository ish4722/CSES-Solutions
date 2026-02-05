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


void dfs(int u,int parent, vector<vector<int>>& adj,vector<int>& values, vector<int>& sum_subtree,vector<int>& parent_vec) {
    parent_vec[u] = parent;
    sum_subtree[u] = values[u];
    for (int v : adj[u]) {
        if (v == parent) continue;
        dfs(v, u, adj, values, sum_subtree,parent_vec);
        sum_subtree[u] += sum_subtree[v];
    }
}

// void update_sum(int u,int root,int parent,vector<vector<int>>& adj, vector<int>& sum_subtree, int diff) {
//     if(u == root) return;
//     sum_subtree[u] += diff;
//     for (int v : adj[u]) {
//         if (v == parent) continue;
//         update_sum(v, root, u, adj, sum_subtree, diff);
//     }
// }

int main(){
    int n, q;
    cin >> n >> q;
    vector<int> values(n+1);
    for (int i = 1; i <=n; i++) {
        cin >> values[i];
    }
    vector<vector<int>> adj(n+1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> sum_subtree(n+1);
    vector<int> parent(n+1);

    dfs(1, -1, adj, values, sum_subtree, parent);




    while (q--) {
    int type;
    cin >> type;

    if (type == 2) {
        int b;
        cin >> b;
        cout << sum_subtree[b] << endl;
    }
    else {
        int b, new_value;
        cin >> b >> new_value;

        int diff = new_value - values[b];
        values[b] = new_value;

        int cur = b;
        while (cur != -1) {
            sum_subtree[cur] += diff;
            cur = parent[cur];
        }
    }
}

    return 0;
} 