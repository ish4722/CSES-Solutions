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

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

#define ez ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define int long long
#define all(x) (x).begin(), (x).end()
#define endl "\n"
#define f(i,a,b) for(int i=a; i<b; i++)

vector<int> topo;

void dfs(int node, vector<vector<int>>& adj, vector<int>& vis) {

    vis[node] = 1;

    for(int v : adj[node]) {
        if(!vis[v]) {
            dfs(v, adj, vis);
        }
    }
}

void solve() {

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    vector<vector<int>> rev(n + 1);

    for(int i = 0; i < m; i++) {

        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        rev[b].push_back(a);
    }

    // Check: can 1 reach everyone?
    vector<int> vis(n + 1, 0);

    dfs(1, adj, vis);

    for(int i = 1; i <= n; i++) {

        if(!vis[i]) {

            cout << "NO\n";
            cout << 1 << " " << i << "\n";

            return;
        }
    }

    // Check: can everyone reach 1?
    vector<int> vis2(n + 1, 0);

    dfs(1, rev, vis2);

    for(int i = 1; i <= n; i++) {

        if(!vis2[i]) {

            cout << "NO\n";
            cout << i << " " << 1 << "\n";

            return;
        }
    }

    cout << "YES\n";
}

signed main() {

    ez;

    int t = 1;

    while(t--) {
        solve();
    }

    return 0;
}