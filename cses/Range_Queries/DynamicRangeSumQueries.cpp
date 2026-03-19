//good qus of fenwich tree in complexity O(log n) for both update and query
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


void update (vector<int> &fenw, int i, int val) {
    for(; i<fenw.size(); i+=i&(-i)) fenw[i] += val;
}

int query(vector<int> &fenw, int i) {
    int sum = 0;
    for(; i>0; i-=i&(-i)) sum += fenw[i];
    return sum;
}

void solve() {
    
    int n,m;
    cin >> n >> m;
    getv(v,n);

    vector<int> fenw(n+1,0);

    f(i,0,n) update(fenw, i+1, v[i]);
    while(m--) {
        int t;
        cin >> t;
        if(t == 1) {
            int i,x;
            cin >> i >> x;
            update(fenw, i, x-v[i-1]);
            v[i-1] = x;
        } else {
            int a,b;
            cin >> a >> b;
            cout << query(fenw, b) - query(fenw, a-1) << endl;
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