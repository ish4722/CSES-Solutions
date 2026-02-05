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


// Children know better than parents. So always decide bottom-up.
using namespace std;

vector<vector<int>> adj;
vector<int> used;
int ans = 0;

void dfs(int u, int parent) {
    for (int v : adj[u]) {
        if (v == parent) continue;
        dfs(v, u);
    }

    for (int v : adj[u]) {
        if (v == parent) continue;
        if (!used[u] && !used[v]) {
            used[u] = used[v] = 1;
            ans++;
            break; // u can be matched only once
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    adj.resize(n + 1);
    used.assign(n + 1, 0);

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0);

    cout << ans << "\n";
    return 0;
}
