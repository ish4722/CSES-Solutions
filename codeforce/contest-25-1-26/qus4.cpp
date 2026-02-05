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
        int n; 
        cin >> n;
        getv(a, n);
        getv(b, n);



        vector<int> pref(n);
        pref[0] = b[0];
        for (int i = 1; i < n; ++i) pref[i] = pref[i-1] + b[i];

        sort(a.begin(), a.end()); 

        set<int> s(all(a));

        int ans = 0;

        for (int x : s) {

            int pos = lower_bound(a.begin(), a.end(), x) - a.begin();
            int m = n - pos;
            int k = upper_bound(pref.begin(), pref.end(), m) - pref.begin();
            
            ans = max(ans, x * k);
        }

        cout << ans << '\n';
    }


signed main() {
    ez;

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}