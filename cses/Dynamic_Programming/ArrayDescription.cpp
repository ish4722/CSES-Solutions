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

//good qus , phir se krna 
int cal(int i, int j, vector<vector<int>>& dp, vector<int>& v, int m) {
    if (i == v.size()) return 1;

    if (dp[i][j] != -1) return dp[i][j];

    int ans = 0;

    if (v[i] != 0) {
        if (j == 0 || abs(v[i] - j) <= 1) {
            ans = cal(i + 1, v[i], dp, v, m);
        }
    }
    else {
        for (int k = 1; k <= m; k++) {
            if (j == 0 || abs(k - j) <= 1) {
                ans = (ans + cal(i + 1, k, dp, v, m)) % mod;
            }
        }
    }

    return dp[i][j] = ans;
}

/*Why i goes from n-1 → 0
At index i you need values from i+1.
So if you did:
for (i = 0; i < n; i++)
you would be asking for dp[i+1][...] before it is computed → wrong.
That’s why:
for (i = n-1; i >= 0; i--)
This is non-negotiable.
👉 This is called reverse DP over index (suffix DP).
3️⃣ Why j goes from 0 → m (and not backward)
Now the important part 👇
Does dp[i][j] depend on:
dp[i][j-1] ❌
dp[i][j+1] ❌
dp[i][j] ❌
No.
It depends ONLY on:
dp[i+1][k]
That means:
All j values at row i are independent
So order of j does not matter
You can write:
for (j = 0; j <= m; j++)
or
for (j = m; j >= 0; j--)
✔ Both are correct
*/
void solve() {
    int n, m;
    cin >> n >> m;

    getv(v, n);
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int j = 1; j <= m; j++) dp[n][j] = 1;

    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j <= m; j++) {

            if (v[i] != 0) {
                if (j == 0 || abs(v[i] - j) <= 1) {
                    dp[i][j] = dp[i + 1][v[i]];
                }
            }
            else {
                if (j == 0) {
                    for (int k = 1; k <= m; k++) {
                        dp[i][j] = (dp[i][j] + dp[i + 1][k]) % mod;
                    }
                } else {
                    for (int k = max(1LL, j - 1); k <= min(m, j + 1); k++) {
                        dp[i][j] = (dp[i][j] + dp[i + 1][k]) % mod;
                    }
                }
            }
        }
    }

    cout << dp[0][0] << endl;
}





signed main() {
    ez;

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}