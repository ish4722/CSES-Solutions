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
#define ll long long

typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef vector<pair<int,int>> vpi;

const int mod = 1000000007;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

void solve() {
    ll n, m, k;
    cin >> n >> m >> k;

    vector<ll> a(n), b(m);
    for (ll &x : a) cin >> x;
    for (ll &x : b) cin >> x;

    string s;
    cin >> s;

    sort(b.begin(), b.end());

    // displacement -> list of robot indices that die at that displacement
    unordered_map<ll, vector<ll>> events;
    events.reserve(2 * n);

    for (ll i = 0; i < n; i++) {
        ll x = a[i];
        auto it = lower_bound(b.begin(), b.end(), x);

        if (it != b.end()) {
            ll dr = *it - x;
            if (dr <= k) events[dr].push_back(i);
        }
        if (it != b.begin()) {
            ll dl = x - *(it - 1);
            if (dl <= k) events[-dl].push_back(i);
        }
    }

    ll cur = 0;
    unordered_set<ll> dead;
    dead.reserve(n * 2);

    for (ll i = 0; i < k; i++) {
        if (s[i] == 'L') cur--;
        else cur++;
//set isliye liya kyuki left and right spike dono mai robot hoga dono kill honge so 
//voh ek baar hi count ho isliye set liya
        if (events.count(cur)) {
            for (ll id : events[cur]) {
                dead.insert(id);
            }
        }

        cout << n - dead.size();
        if (i + 1 < k) cout << ' ';
    }
    cout << '\n';   
}


signed main() {
    ez;

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}