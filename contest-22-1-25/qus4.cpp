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


int get_msb(int n) {
    int msb = 1;
    while ((msb * 2) <= n) {
        msb *= 2;
    }
    return msb;
}

void solve() {
    int n;
    cin >> n;

    if ((n & (n - 1)) == 0) {
        cout << "-1\n";
        return;
    }

    vector<int> p(n + 1);
    iota(p.begin(), p.end(), 0);

    int current_n = n;

    while (current_n > 0) {
        int L = get_msb(current_n);
        
        if (current_n % 2 == 1) {

            
        cout << n - 1 << " "; 
        
        for (int i = 2; i < n - 1; i += 2) {
            cout << i + 1 << " " << i << " ";
        }
        
        cout << 1 << " " << n << "\n";
        }
        

        
        for (int i = 1; i <= current_n - L; ++i) {
            swap(p[i], p[i + L]);
        }
        

        current_n = L - 1;
    }

    for (int i = 1; i <= n; ++i) {
        cout << p[i] << " ";
    }
    cout << "\n";
}

signed main() {
    ez;

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}