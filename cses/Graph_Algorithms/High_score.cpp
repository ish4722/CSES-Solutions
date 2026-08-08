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
#include <climits>
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

    vector<tuple<int,int,int>> edges;
    vector<vector<int>> rev(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({a, b, c});
        rev[b].push_back(a);
    }

    // Mark all nodes that can reach n
    vector<int> canReach(n + 1, 0);
    queue<int> q;
    q.push(n);
    canReach[n] = 1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : rev[u]) {
            if (!canReach[v]) {
                canReach[v] = 1;
                q.push(v);
            }
        }
    }

    const long long NEG_INF = -(1LL << 60);
    vector<long long> dist(n + 1, NEG_INF);
    dist[1] = 0;

    // Bellman-Ford for maximum distance
    for (int i = 1; i <= n - 1; i++) {
        for (auto [u, v, w] : edges) {
            if (dist[u] == NEG_INF) continue;
            dist[v] = max(dist[v], dist[u] + w);
        }
    }

    // Check for useful positive cycles
    for (auto [u, v, w] : edges) {
        if (dist[u] == NEG_INF) continue;

        if (dist[v] < dist[u] + w && canReach[v]) {
            cout << -1 << endl;
            return;
        }
    }

    cout << dist[n] << endl;
}

signed main() {
    ez;

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}