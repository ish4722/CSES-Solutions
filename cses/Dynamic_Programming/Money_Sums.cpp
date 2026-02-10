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

const int MAX_SUM = 100000;
bool vis[101][MAX_SUM + 1];
bool reachable[MAX_SUM + 1];

void cal(int i, int sum, vector<int>& v) {
    if (vis[i][sum]) return;
    vis[i][sum] = true;

    if (i == v.size()) {
        if (sum > 0) reachable[sum] = true;
        return;
    }

    // skip coin
    cal(i + 1, sum, v);

    // take coin
    if (sum + v[i] <= MAX_SUM) {
        cal(i + 1, sum + v[i], v);
    }
}



void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    cal(0, 0, v);

    vector<int> ans;
    for (int s = 1; s <= MAX_SUM; s++) {
        if (reachable[s]) ans.push_back(s);
    }

    cout << ans.size() << "\n";
    for (int x : ans) cout << x << " ";
}



signed main() {
    ez;

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}