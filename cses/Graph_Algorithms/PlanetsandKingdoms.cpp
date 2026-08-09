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

    for(int i : adj[node]) {
        if(!vis[i]) {
            dfs(i, adj, vis);
        }
    }

    topo.push_back(node);
}

void dfs2(int node, vector<vector<int>>& adj, vector<int>& vis,vector<int> &representative) {

    representative.push_back(node);
    vis[node] = 1;

    for(int i : adj[node]) {
        if(!vis[i]) {
            dfs2(i, adj, vis,representative);
        }
    }
}

void solve() {

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    vector<vector<int>> adj2(n + 1);

    f(i, 0, m) {

        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj2[b].push_back(a);
    }

    vector<int> vis(n + 1, 0);
    vector<int> vis2(n + 1, 0);

    // First DFS
    f(i, 1, n + 1) {
        if(!vis[i]) {
            dfs(i, adj, vis);
        }
    }

    // Second DFS in reverse finishing order
    int components = 0;
    vector<vector<int>> representatives;

    for(int i = n - 1; i >= 0; i--) {

        int node = topo[i];

        if(!vis2[node]) {
            vector<int> representative;
            components++;
            dfs2(node, adj2, vis2,representative);
            representatives.push_back(representative);
        }
    }
    cout<<components<<endl;
    vector<int> ans(n + 1, 0);
    for(int i=0;i<representatives.size();i++){
        for(auto node:representatives[i]){
            ans[node] = i+1;
        }
    }
    f(i, 1, n + 1) {
        cout << ans[i] << " ";
    }

}

signed main() {

    ez;

    int t = 1;

    while(t--) {
        solve();
    }

    return 0;
}