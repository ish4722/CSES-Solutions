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

void dfs(int node,vector<vector<int>>& adj, vector<int>& parent, vector<int>& depth){
    for(auto child: adj[node]){
        if(child!=parent[node]){
            parent[child]=node;
            depth[child]=depth[node]+1;
            dfs(child,adj,parent,depth);
        }
    }
}

void dfs2(int u, int p, vector<vector<int>>& adj, vector<int>& cnt) {
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs2(v, u, adj, cnt);
        cnt[u] += cnt[v];
    }
}
int lca(int a, int b, vector<int>& depth , vector<vector<int>>& up){
    if(depth[a]<depth[b]){
        swap(a,b);
    }

    int LOG=up[0].size();

    int diff=depth[a]-depth[b];
    for(int j=0;j<LOG;j++){
        if(diff & (1<<j)){
            a=up[a][j];
        }
    }

    if(a==b){
        return a;
    }

    for(int j=LOG-1;j>=0;j--){
        if(up[a][j]!=up[b][j]){
            a=up[a][j];
            b=up[b][j];
        }
    }
    return up[a][0];
}
void solve() {
    int n,m;
    cin>>n>>m;

    vector<vector<int>> adj(n+1);
    f(i,0,n-1){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int log=20;
    vector<vector<int>> up(n+1, vector<int>(log));
    vector<int> parent(n+1, -1);
    vector<int> depth(n+1, 0);
    dfs(1, adj, parent,depth);
    for(int i=1;i<=n;i++){
        up[i][0]=parent[i];
    }
    for(int j=1;j<log;j++){
        for(int i=1;i<=n;i++){
            up[i][j]=up[up[i][j-1]][j-1];
        }
    }

    vector<int> cnt(n+1,0);
    while(m--){
        int a,b;
        cin>>a>>b;
        int l=lca(a,b,depth,up);
        cnt[a]++;
        cnt[b]++;
        cnt[l]--;
    }
    dfs2(1,-1,adj,cnt);
}

signed main() {
    ez;

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}