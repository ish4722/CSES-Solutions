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

void solve() {
    int n, k;
    cin >> n >> k;

    // n = 2^d
    int d = 0;
    while ((1LL << d) < n) d++;

    // Precompute binomial coefficients up to 60
    static int C[61][61];
    static bool done = false;
    if (!done) {
        done = true;
        f(i, 0, 61) {
            C[i][0] = C[i][i] = 1;
            f(j, 1, i) {
                C[i][j] = C[i-1][j-1] + C[i-1][j];
            }
        }
    }

    int ans = 0;

    // Process full blocks [2^b, 2^{b+1} - 1]
    f(b, 0, d) {
        int need = k - b;
        if (need <= 0) {
            ans += (1LL << b);
        } else if (need <= b) {
            f(i, need, b + 1) {
                ans += C[b][i];
            }
        }
    }

    // Special case: a = 2^d
    // moves = d + 1
    if (d + 1 > k) ans++;

    cout << ans << endl;
}

signed main() {
    ez;

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}
  