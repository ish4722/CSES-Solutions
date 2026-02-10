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

#define int long long
const long long INF = 4e18;

vector<long long> X, lowv, highv;
vector<vector<long long>> memo;

// dp(i, s):
// i -> column index
// s = 0 -> end at low[i]
// s = 1 -> end at high[i]
long long dp(int i, int s) {
    if (memo[i][s] != -1) return memo[i][s];

    // base case: starting column (Ax)
    if (i == 0) {
        return memo[i][s] = 0;
    }

    long long dx = X[i] - X[i - 1];
    long long len = highv[i] - lowv[i];
    long long cost = dx + len;

    long long ans;
    if (s == 0) {
        // end at low[i]
        ans = min(
            dp(i - 1, 0) + llabs(highv[i] - lowv[i - 1]),
            dp(i - 1, 1) + llabs(highv[i] - highv[i - 1])
        ) + cost;
    } else {
        // end at high[i]
        ans = min(
            dp(i - 1, 0) + llabs(lowv[i] - lowv[i - 1]),
            dp(i - 1, 1) + llabs(lowv[i] - highv[i - 1])
        ) + cost;
    }

    return memo[i][s] = ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n, ax, ay, bx, by;
        cin >> n >> ax >> ay >> bx >> by;

        vector<int> x(n), y(n);
        for (int i = 0; i < n; i++) cin >> x[i];
        for (int i = 0; i < n; i++) cin >> y[i];

        // store min/max y for each x
        map<int, int> mn, mx;
        mn[ax] = mx[ax] = ay;
        mn[bx] = mx[bx] = by;

        for (int i = 0; i < n; i++) {
            if (!mn.count(x[i])) mn[x[i]] = y[i];
            else mn[x[i]] = min(mn[x[i]], y[i]);

            mx[x[i]] = max(mx[x[i]], y[i]);
        }

        // extract columns in increasing x
        X.clear();
        lowv.clear();
        highv.clear();

        for (auto &p : mn) {
            X.push_back(p.first);
            lowv.push_back(p.second);
            highv.push_back(mx[p.first]);
        }

        int k = X.size();
        memo.assign(k, vector<long long>(2, -1));

        // final answer (must end at low of Bx column)
        cout << dp(k - 1, 0) << '\n';
    }

    return 0;
}
