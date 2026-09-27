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
int n;
int cal(int mask,int u,vector<vector<int>>& adj,vector<vector<int>>& dp){
    if(mask== (1<<adj.size())-1){
        return u==n-1;
    }
    if(dp[mask][u]!=-1) return dp[mask][u];

    long long ans=0;
    for(int v:adj[u]){
        if(mask & (1<<v)) continue;

        int new_mask=mask|(1<<v);
        if(v==n-1 && new_mask!=(1<<n)-1) continue;

        ans+=cal(new_mask,v,adj,dp);
    }
    return dp[mask][u]=ans;
}
void solve() {
    
}

signed main() {
    ez;

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}