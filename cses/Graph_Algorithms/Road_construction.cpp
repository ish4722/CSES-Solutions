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


vector<int> parent,sz;

int parent_find(int a) {
    if (parent[a] == a) return a;
    return parent[a] = parent_find(parent[a]);
}

bool unionbysize(int a, int b) {
    int u = parent_find(a);
    int v = parent_find(b);

    if (u == v) return false;

    if (sz[u] < sz[v]) swap(u, v);

    parent[v] = u;
    sz[u] += sz[v];

    return true;
}

void solve() {
    int n, m;
    cin >> n >> m;

    parent.resize(n + 1);
    sz.assign(n + 1, 1);

    for (int i = 1; i <= n; i++) parent[i] = i;

    int components = n;
    int maxi = 1;

    while (m--) {
        int a, b;
        cin >> a >> b;

        if (unionbysize(a, b)) {
            components--;

            int root = parent_find(a);
            maxi = max(maxi, sz[root]);
        }

        cout << components << " " << maxi << '\n';
    }
}

signed main() {
    ez;

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}