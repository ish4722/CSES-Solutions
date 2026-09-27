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


void dfs1(int u, int par, vector<int>& dp, vector<vector<int>>& adj, int MOD) {

    dp[u] = 1;

    for(auto v : adj[u]) {

        if(v == par) continue;

        dfs1(v, u, dp, adj, MOD);

        dp[u] *= (dp[v] + 1);
// dp[v] ways if v is black and 1 way v is white =dp[u] total ways it can be black
        dp[u] %= MOD;
    }
}


void dfs2(int u, int par, vector<int>& dp, vector<int>& up,
          vector<int>& ans, vector<vector<int>>& adj, int MOD) {
// dp has only info abt itself not abt others so for it we use up
    ans[u] = dp[u] * up[u] % MOD;

    for(auto v : adj[u]) {

        if(v == par) continue;

        int other = 1;

        for(auto x : adj[u]) {
// we want to find the ways of all other children of u 
//except v so we multiply all other children ways
            if(x == par || x == v) continue;

            other *= (dp[x] + 1);
            other %= MOD;
        }

        up[v] = ( 1 + up[u] * other ) % MOD;

        dfs2(v, u, dp, up, ans, adj, MOD);
    }
}


void solve() {

    int n,m;
    cin >> n >> m;

    vector<vector<int>> adj(n+1);

    f(i,0,n-1) {

        int a,b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> dp(n+1,1);

    // DFS 1
    dfs1(1,0,dp,adj,m);


    vector<int> up(n+1,1);
    vector<int> ans(n+1,1);

    // Root has nothing above it
    up[1] = 1;

    dfs2(1,0,dp,up,ans,adj,m);


    f(i,1,n+1) {
        cout << ans[i] << " ";
    }

    cout << endl;
}


signed main() {

    ez;

    int t = 1;
    // cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}
