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


void dfs(int node, vector<vector<int>>& tree, vector<int>& subordinates) {
    for (int child : tree[node]) {
        dfs(child, tree, subordinates);
        subordinates[node] += 1 + subordinates[child];
    }
}

void solve() {
    vector<vector<int>> tree;

    int n; cin >> n;
    tree.resize(n + 1);
    f(i, 2, n + 1) {
        int p; 
        cin >> p;
        tree[p].push_back(i);
    }
    vector<int> subordinates(n + 1, 0);
    dfs(1, tree, subordinates);

    f(i, 1, n + 1) {
        cout << subordinates[i] << " ";
    }

}

signed main() {
    ez;

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}