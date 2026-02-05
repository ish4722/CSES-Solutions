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
vector<int> sub;
vector<int> dp, ans;
int n;

void dfs1(int u, int parent) {
    sub[u] = 1;//number of nodes in subtree of u
    dp[u] = 0;//sum of distances from u to nodes only in its subtree

    for (int v : adj[u]) {
        if (v == parent) continue;
        dfs1(v, u);
        sub[u] += sub[v];
        dp[u] += dp[v] + sub[v];
    }
}

void dfs2(int u, int parent) {
    for (int v : adj[u]) {
        if (v == parent) continue;
        ans[v] = ans[u] - sub[v] + (n - sub[v]);
        dfs2(v, u);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    adj.resize(n + 1);
    sub.resize(n + 1);
    dp.resize(n + 1);
    ans.resize(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs1(1, 0);        // subtree DP
    ans[1] = dp[1];   // root answer
    dfs2(1, 0);        // rerooting

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";

    return 0;
}
