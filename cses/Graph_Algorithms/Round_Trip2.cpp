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
#define getv(v, n) vector<int> v(n); f(i,0,n) cin >> v[i];

typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef vector<pair<int,int>> vpi;

const int mod = 1000000007;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
//this is a uniderectional graph

bool dfs(int u, vector<vector<int>>& adj, vector<int>& color, vector<int>& parent) {
    color[u] = 1; // mark as visiting
    for (int v : adj[u]) {
        if (color[v] == 0) { // if not visited
            parent[v] = u;
            if (dfs(v, adj, color, parent)) {
                return true;
            }
        } else if (color[v] == 1) { // found a back edge
            // print the cycle
            vector<int> cycle;
            cycle.push_back(v);
            int cur = u;
            while (cur != v) {
                cycle.push_back(cur);
                cur = parent[cur];
            }
            cycle.push_back(v);
            reverse(cycle.begin(), cycle.end());
            cout << cycle.size() << endl;
            for (int x : cycle) {
                cout << x << " ";
            }
            cout << endl;
            return true;
        }
    }
    color[u] = 2; // mark as visited
    return false;
}
void solve() {
    int n,m;
    cin>>n>>m;

    vector<vector<int>> adj(n+1);

    f(i,0,m){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
    }

    vector<int> parent(n+1, -1);
    vector<int> color(n+1, 0);
    bool found=false;
//directed cycle to backtrack we cant use bfs
    f(i,1,n+1){
        if(color[i]==0){
            if(dfs(i, adj, color, parent)){
                found=true;
                break;
            }
        }
    }
    if(!found){
        cout<<"IMPOSSIBLE"<<endl;
    }
}

signed main() {
    ez;

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}