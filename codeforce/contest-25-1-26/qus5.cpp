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
#define int long long
const int INF = 1e18;


void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int &x : a) cin >> x;

    vector<int> cnt(n + 1, 0);
    for (int x : a) cnt[x]++;

  
    vector<int> vals;
    for (int i = 2; i <= n; i++) {
        if (cnt[i]) vals.push_back(i);
    }

    vector<int> dp(n + 1, INF);
    dp[1] = 0;

    for (int v : vals) {
        for (int m = v; m <= n; m += v) {
            if (dp[m / v] != INF) {
                dp[m] = min(dp[m], dp[m / v] + 1);
            }
        }
    }


    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            cout << (cnt[1] ? 1 : -1) << " ";
        } else {
            cout << (dp[i] == INF ? -1 : dp[i]) << " ";
        }
    }
    cout << "\n";
}

signed main() {
    ez;

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}