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

// #include "debug.hpp"

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
#define ez ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define int long long
#define all(x) (x).begin(), (x).end()
#define endl "\n"

typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef vector<pair<int,int>> vpi;

const int mod = 1000000007;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }





int calc(int a, int b, bool white_on_top) {
    int used_w = 0, used_d = 0;
    int layers = 0;
    int size = 1;

    while (true) {
        if ((layers % 2 == 0) == white_on_top) {
            used_w += size;
            if (used_w > a) break;
        } else {
            used_d += size;
            if (used_d > b) break;
        }
        layers++;
        size *= 2;
    }
    return layers;
}

void solve() {
    int a, b;
    cin >> a >> b;

    int ans1 = calc(a, b, true);   
    int ans2 = calc(a, b, false);  

    cout << max(ans1, ans2) << endl;
}




signed main() {
    ez;

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

