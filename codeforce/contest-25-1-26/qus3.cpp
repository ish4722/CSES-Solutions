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
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n, q;
        cin >> n >> q;
        vector<ll> a(n), b(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];

        // c[i] = max(a[i], b[i])
        vector<ll> c(n);
        for (int i = 0; i < n; ++i) c[i] = max(a[i], b[i]);

        // suf[i] = max_{k >= i} c[k]  (computed right-to-left)
        vector<ll> suf(n);
        for (int i = n - 1; i >= 0; --i) {
            if (i == n - 1) suf[i] = c[i];
            else suf[i] = max(c[i], suf[i + 1]);
        }

        // prefix sums of suf to answer range sums quickly
        vector<ll> pref(n);
        for (int i = 0; i < n; ++i) {
            pref[i] = suf[i] + (i ? pref[i - 1] : 0LL);
        }

        // answer queries
        for (int i = 0; i < q; ++i) {
            int l, r;
            cin >> l >> r;
            --l; --r;
            ll ans = pref[r] - (l ? pref[l - 1] : 0LL);
            cout << ans << (i + 1 == q ? '\n' : ' ');
        }
    }
    return 0;
}
