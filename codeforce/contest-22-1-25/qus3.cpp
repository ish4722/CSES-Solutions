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
    // int n;
    // cin >> n;

    // if (n % 2 == 0) {
    //     cout << n << " ";
    //     for (int i = 2; i < n; ++i) {
    //         cout << (i ^ 1) << " ";
    //     }
    //     cout << 1 << "\n";
    // } else {
    //           cout << n - 1 << " ";
    //     for (int i = 2; i < n - 1; ++i) {
    //         cout << (i ^ 1) << " ";
    //     }
    //     cout << 1 << " " << n << "\n";
    // }
    int n;
    cin >> n;

    if (n % 2 == 0) {
 
        cout << n << " "; 
        

        for (int i = 2; i < n; i += 2) {
            cout << i + 1 << " " << i << " ";
        }
        
        cout << 1 << "\n"; 
    } else {
        cout << n - 1 << " "; 
        
        for (int i = 2; i < n - 1; i += 2) {
            cout << i + 1 << " " << i << " ";
        }
        
        cout << 1 << " " << n << "\n";
    }
}

signed main() {
    ez;

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}