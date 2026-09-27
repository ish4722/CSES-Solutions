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

void dfs1(int u,int p,vector<vector<int>>& adj,vector<int>& sub,vector<int>& dp){

    for(int v:adj[u]){
        if(v==p) continue;
        dfs1(v,u,adj,sub,dp);
        sub[u]+=sub[v];
        dp[u]+=dp[v]+sub[v];
    }
}
void dfs2(int u,int p,vector<vector<int>>& adj,vector<int>& sub,vector<int>& dp,vector<int>& ans,int n){
    for(int v:adj[u]){
        if(v==p) continue;
        ans[v]=ans[u]-sub[v]+(n-sub[v]);
        dfs2(v,u,adj,sub,dp,ans,n);
    }
}
void solve() {
    int n;
    cin>> n;
    vector<vector<int>> adj(n+1);
    vector<int> sub(n+1,1),ans(n+1),dp(n+1,0);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs1(1,0,adj,sub,dp);
    ans[1]=dp[1];
    dfs2(1,0,adj,sub,dp,ans,n);
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
}

signed main() {
    ez;

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}