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


int cal(int mask, int n, vector<vector<int>>& adj, vector<int>& dp) {

    if(mask == (1 << n) - 1) return 1;

    if(dp[mask] != -1) return dp[mask];

    int man = __builtin_popcount(mask);
//we dont need two state bcz we only wnat to see how many women are busy
//women==men busy so no two state required [mask][man] not required
//mask is number of women busy
    long long ans = 0;

    for(int woman : adj[man]) {
        if(mask & (1 << woman)) continue;

        int newMask = mask | (1 << woman);

        ans = (ans + cal(newMask, n, adj, dp)) % mod;;
    }

    return dp[mask] = ans;
}
void solve() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int x;
            cin >> x;
//adj[i] = women compatible with man i
            if(x) adj[i].push_back(j);
        }
    }
    vector<int> dp(1LL << n, -1);
    //we start from 0 as 0 women initally are busy
    cout << cal(0, n, adj, dp) << endl;
}

signed main() {
    ez;

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}