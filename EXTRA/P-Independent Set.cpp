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
const long long MOD = 1e9 + 7;

vector<vector<int>> adj;
vector<vector<long long>> dp;

void dfs(int u, int par){

    dp[u][0] = 1;
    dp[u][1] = 1;

    for(auto v : adj[u]){

        if(v == par) continue;

        dfs(v,u);

        dp[u][0] = dp[u][0] * (dp[v][0] + dp[v][1]) % MOD;

        dp[u][1] = dp[u][1] * dp[v][0] % MOD;
    }
}
void solve() {
    int n;
    cin >> n;

    adj.resize(n+1);
    dp.resize(n+1, vector<long long>(2,0));

    for(int i=0;i<n-1;i++){

        int x,y;
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1,0);

    cout << (dp[1][0] + dp[1][1]) % MOD << endl;
}

signed main() {
    ez;

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}