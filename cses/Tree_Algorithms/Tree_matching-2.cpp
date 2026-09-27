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

void dfs(int node, int parent, vector<vector<int>>& adj, vector<vector<int>>& dp) {
    for(auto u : adj[node]){
        if(u != parent){
            dfs(u, node, adj, dp);
            dp[node][0]+= max(dp[u][0], dp[u][1]);
        }
    }
    dp[node][1] = -1e9;
    for(auto u : adj[node]){
        if(u != parent){
            dp[node][1] = max(dp[node][1], dp[node][0] - max(dp[u][0], dp[u][1]) + 1 + dp[u][0]);
        }
    }
}
void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n+1);
    f(i,0,n-1){
        int a,b; 
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<vector<int>> dp(n+1,vector<int>(2,0));

    dfs(1,0,adj,dp);
    cout<<max(dp[1][0],dp[1][1])<<endl;
}

signed main() {
    ez;

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}
