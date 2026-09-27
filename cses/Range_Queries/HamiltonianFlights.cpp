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

const int MOD = 1000000007;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int n, m;
vector<vector<int>> adj;
vector<vector<int>> dp;

    int cal(int mask, int u) {
        // All cities visited
        if (mask == (1 << n) - 1) {
            return u == n - 1;
        }

        if (dp[mask][u] != -1)
            return dp[mask][u];

        long long ans = 0;

        for (int v : adj[u]) {

            // Already visited
            if (mask & (1 << v)) continue;
            int newmask=mask | (1 << v);
            // Don't reach destination before visiting all cities
            if (v == n - 1 && newmask != (1 << n) - 1) continue;

            ans += cal(mask | (1 << v), v);

            if (ans >= MOD) ans -= MOD;
        }
        return dp[mask][u] = ans;
    }

void solve() {
    cin >> n >> m;

    adj.resize(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        --u;
        --v;

        adj[u].push_back(v);
    }
    int total = 1 << n;
    dp.assign(total, vector<int>(n, -1));

    cout << cal(1, 0) << '\n';
}

signed main() {
    ez;

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}