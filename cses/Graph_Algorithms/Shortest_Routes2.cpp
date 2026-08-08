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
    int n,m,q;
    cin >> n >> m >> q;

    vector<vector<pair<int,int>>> adj(n+1);
    f(i,0,m) {
        int a,b,c;
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    vector<vector<int>> dist(n+1, vector<int>(n+1, 1e18));

    f(i,1,n+1) {
        dist[i][i] = 0;
        for(auto [j,w]: adj[i]) {
            dist[i][j] = min(dist[i][j], w);
        }
    }
    
    f(k,1,n+1) {
        f(i,1,n+1) {
            f(j,1,n+1) {
                if(dist[i][k] < 1e18 && dist[k][j] < 1e18) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    f(i,0,q) {
        int a,b;
        cin >> a >> b;
        if(dist[a][b] == 1e18) cout << -1 << endl;
        else cout << dist[a][b] << endl;
    }

}

signed main() {
    ez;

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}