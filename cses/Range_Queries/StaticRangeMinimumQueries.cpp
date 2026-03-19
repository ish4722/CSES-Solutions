// Very good qus to understand the concept of sparse table

/*
The Mindset: "Precompute to Save Time"

Imagine you are a librarian. People keep asking you, "What is the shortest book between shelf A and shelf B?"

The Slow Way: Every time someone asks, you walk to the shelves and check every single book. 
If the library is huge (2⋅10^5 books) and people ask 2⋅10^5 times, you’ll be exhausted and slow.

The Smart Way (Sparse Table): You spend some time beforehand making a "cheat sheet." You write down the shortest book for sections of size 1, 2, 4, 8, 16, and so on (powers of 2).

When a query comes in for a range like 5 books, you don't check all 5. You look at your cheat sheet for the shortest book in the first 4 books and the last 4 books of that range. Since those two groups overlap, the overall minimum must be the smaller of those two precomputed values.

The Strategy: Sparse Table

For this specific problem, a Sparse Table is the gold standard.

Preprocessing: We build a table where st[i][j] stores the minimum value in the range starting at i with length 2 
j
 . This takes O(nlogn) time.

Querying: Any range [a,b] can be covered by two overlapping blocks of the largest possible power of 2 that fits. This takes O(1) time per query.

Example Walkthrough

Array: [3, 2, 4, 5, 1, 1, 5, 3]
Query: Range [2, 4] (Values: 2, 4, 5)

Length of range is 4−2+1=3.

The biggest power of 2 that fits in 3 is 2 
1
 =2.

We compare:

Minimum of first 2 elements ([2, 4]): 2

Minimum of last 2 elements ([4, 5]): 4

The answer is min(2,4)=2.
*/

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
    int n,m;
    cin >> n >> m;

    getv(v,n);

    vector<vector<int>> st(n, vector<int>(20));
    // Preprocessing: Build the Sparse Table
    for(int i=0; i<n; i++) {
        st[i][0] = v[i];
    }
    // Build the Sparse Table for intervals of length 2^j 
    // i is the starting index and j is the power of 2
    for(int j=1; (1<<j) <= n; j++) {
        for(int i=0; i+(1<<j) <= n; i++) {
            st[i][j] = min(st[i][j-1], st[i+(1<<(j-1))][j-1]);
        }
    }

    // Querying: For each query, find the minimum in the range [a, b]

    while(m--) {
        int a,b;
        cin >> a >> b;
        a--; b--; // Convert to 0-based indexing

        int length = b - a + 1;
        int j = log2(length); // Largest power of 2 that fits in the range

        // The minimum is the smaller of the two overlapping blocks
        int ans = min(st[a][j], st[b-(1<<j)+1][j]);
        cout << ans << endl;
    }


}

signed main() {
    ez;

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}