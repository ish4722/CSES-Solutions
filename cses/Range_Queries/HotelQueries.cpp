//GOOD QUS
//Segment Tree ka implementation 

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


void update(int &a, int b) {
    a += b;
    if (a >= mod) a -= mod;
}   

int query(int a, int b) {
    int res = a - b;
    if (res < 0) res += mod;
    return res;
}
void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;

    vector<int> h(n + 1);
    for (int i = 1; i <= n; i++) cin >> h[i];

    // Build a Segment Tree to store the maximum value in each range.
    // This allows us to find the first hotel with enough rooms in O(log n).
    int size = 1;
    while (size < n) size *= 2;
    vector<int> tree(2 * size, 0);

    // Build the tree
    for (int i = 1; i <= n; i++) {
        tree[size + i - 1] = h[i];
    }
    for (int i = size - 1; i > 0; i--) {
        tree[i] = max(tree[2 * i], tree[2 * i + 1]);
    }

    while (m--) {
        int x;
        cin >> x;

        // Find the first hotel with at least x rooms using the segment tree.
        int pos = 1;
        if (tree[pos] < x) {
            cout << 0 << " ";
            continue;
        }
        while (pos < size) {
            if (tree[2 * pos] >= x) {
                pos = 2 * pos;
            } else {
                pos = 2 * pos + 1;
            }
        }
        int hotel_index = pos - size + 1;
        cout << hotel_index << " ";
        // Update the segment tree to reflect the booking.
        tree[pos] -= x;
        for (pos /= 2; pos > 0; pos /= 2) {
            tree[pos] = max(tree[2 * pos], tree[2 * pos + 1]);
        }
    }
}

signed main() {
    ez;

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}