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

//very nice qus * must do
vector<int> bitcnt(31, 0);
int cur_or = 0;

void add_num(int x) {
    for(int i = 0; i < 31; i++) {
        if(x & (1LL << i)) {
            if(bitcnt[i] == 0)
                cur_or |= (1LL << i);
            bitcnt[i]++;
        }
    }
}

void remove_num(int x) {
    for(int i = 0; i < 31; i++) {
        if(x & (1LL << i)) {
            bitcnt[i]--;
            if(bitcnt[i] == 0)
                cur_or &= ~(1LL << i);
        }
    }
}

void solve() {
    int n, k;
    cin >> n >> k;

    int x, a, b, c;
    cin >> x >> a >> b >> c;

    queue<int> q;
    int ans = 0;

    for(int i = 0; i < n; i++) {
        add_num(x);
        q.push(x);

        if((int)q.size() > k) {
            remove_num(q.front());
            q.pop();
        }

        if(i >= k - 1)
            ans ^= cur_or;

        x = (a * x + b) % c;
    }

    cout << ans << endl;
}

signed main() {
    ez;
    solve();
    return 0;
}
