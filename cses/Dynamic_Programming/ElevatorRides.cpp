//bitmask dp in detail explained

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
/*
🧠 Step 0 — When Should Bitmask DP Even Come To Mind?
Immediately think about bitmask when:
n ≤ 20
            You need to choose / arrange / partition elements
            Order is irrelevant (subset matters)
            Brute force feels exponential
            Because:
            when n≤20
            That’s manageable.
🧠 Step 1 — Ask: What Is My State?

In any DP, first question is:
What information fully defines my situation?

In Elevator Rides, what matters?
Which people are already transported
How many rides used
Current ride load
The key realization:
We don’t care about order.
We only care about which people are done.
So state becomes:
mask = subset of completed people
That’s the compression step.


🧠 Step 2 — What Does dp[mask] Mean?
                    Always define this clearly.
                    For Elevator Rides:
                    dp[mask] = best solution for transporting people in this mask
                    But “best” must be precise.
                    Here:
                    dp[mask] = {minimum rides, current weight in last ride}
                    That’s a complete description of the state.

🧠 Step 3 — How Do We Move Between States?
                    In subset DP, transitions look like:
                    mask  →  mask | (1 << j)
                    Meaning:
                    Add person j to the current subset.
                    So the general pattern becomes:
                    For every mask:
                        For every element not in mask:
                            Try adding it
                    That’s the skeleton of almost every bitmask DP.

🧠 Step 4 — What Is the Base Case?
        For Elevator:
        dp[0] = {1 ride, 0 weight}
        We start with an empty elevator.

🧠 Step 5 — How Do We Compare States?
            This is where many people mess up.
            For Elevator:
            Primary objective → minimize rides
            Secondary → minimize last ride weight
            So comparison rule:
            if rides smaller → better
            if rides equal → smaller weight better

// important part

🔥 Full Algorithm Skeleton
dp[0] = {1, 0}

for mask from 0 to (1<<n)-1:
    for each person j not in mask:

        current = dp[mask]

        if current.weight + w[j] <= x:
            new_state = {current.rides, current.weight + w[j]}
        else:
            new_state = {current.rides + 1, w[j]}

        dp[mask | (1<<j)] = min(dp[mask | (1<<j)], new_state)


Answer:
dp[(1<<n) - 1].rides
*/
void solve() {
    int n,x;
    cin >> n >> x;
    getv(v,n);

    vector<pair<int,int>> dp(1<<n, {n+1,0}); // {rides, weight}
    dp[0] = {1,0};

    for(int mask=0; mask<(1<<n); mask++) {
        for(int j=0; j<n; j++) {
            if((mask & (1<<j)) == 0) { // if j not in mask
                auto current = dp[mask];
                pair<int,int> new_state;
                if(current.second + v[j] <= x) {
                    new_state = {current.first, current.second + v[j]};
                } else {
                    new_state = {current.first + 1, v[j]};
                }
                dp[mask | (1<<j)] = min(dp[mask | (1<<j)], new_state);
            }
        }
    }

    cout << dp[(1<<n) - 1].first << endl;

    

}

signed main() {
    ez;

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}