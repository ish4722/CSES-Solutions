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
    long long h;
    cin >> n >> m >> h;

    vector<long long> cur(n);
    for (int i = 0; i < n; i++) cin >> cur[i];

    vector<pair<int,long long>> history;
    vector<char> used(n, 0);

    while (m--) {
        int b;
        long long c;
        cin >> b >> c;
        b--;

        if (!used[b]) {
            history.push_back({b, cur[b]});
            used[b] = 1;
        }

        cur[b] += c;

        if (cur[b] > h) {
            for (auto &p : history)
                cur[p.first] = p.second;

            history.clear();
            fill(used.begin(), used.end(), 0);
        }
    }

    for (long long x : cur) cout << x << " ";
    cout << "\n";
}





signed main() {
    ez;

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}