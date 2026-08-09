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
    int n, m;
    cin >> n >> m;

    vector<int> a(n + 1), pos(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }

    int ans = 1;
    for (int i = 1; i < n; i++)
        if (pos[i] > pos[i + 1])
            ans++;

    while (m--) {
        int l, r;
        cin >> l >> r;

        int x = a[l];
        int y = a[r];

        set<pair<int,int>> check;

        if (x > 1) check.insert({x - 1, x});
        if (x < n) check.insert({x, x + 1});
        if (y > 1) check.insert({y - 1, y});
        if (y < n) check.insert({y, y + 1});

        // Remove old contributions
        for (auto [u, v] : check)
            if (pos[u] > pos[v])
                ans--;

        // Perform swap
        swap(a[l], a[r]);
        swap(pos[x], pos[y]);

        // Add new contributions
        for (auto [u, v] : check)
            if (pos[u] > pos[v])
                ans++;

        cout << ans << '\n';
    }
}
    


signed main() {
    ez;

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}