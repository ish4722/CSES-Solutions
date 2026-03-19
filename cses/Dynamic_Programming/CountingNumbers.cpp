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
#include <cstring>

using namespace std;

//good qus

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



string A, B;
int dp[20][2][2][11][2];  
// pos, tightLow, tightHigh, prevDigit(0-9,10=no prev), started

int cal(int pos, int tightLow, int tightHigh, int prev, int started) {
/*
tightLow = 1  → still equal to prefix of A we can use only digit greater than or equal to A[pos]
tightLow = 0  → already greater than A somewhere before so we can use 0-9 any digit
*/
/*
tightHigh = 1 → still equal to prefix of B we can use only digit less than or equal to B[pos]
tightHigh = 0 → already less than B somewhere before so we can use 0-9 any digit
*/
/*
started = 0  → number is still all leading zeros
started = 1  → real number has begun
*/
    if (pos == B.size())
        return 1;


    if (dp[pos][tightLow][tightHigh][prev][started] != -1) return dp[pos][tightLow][tightHigh][prev][started];

    int res = 0;

    int low = tightLow ? A[pos] - '0' : 0;
    int high = tightHigh ? B[pos] - '0' : 9;

    for (int d = low; d <= high; d++) {

        int newStarted = started || (d != 0);

        // avoid equal adjacent digits
        if (newStarted && started && d == prev)
            continue;

        int newTightLow = tightLow && (d == low);
        int newTightHigh = tightHigh && (d == high);

        int newPrev = newStarted ? d : 10;

        res += cal(pos + 1, newTightLow, newTightHigh, newPrev, newStarted);
    }

    return dp[pos][tightLow][tightHigh][prev][started] = res;;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> A >> B;

    // pad A with leading zeros
    while (A.size() < B.size())
        A = "0" + A;

    memset(dp, -1, sizeof(dp));

    cout << cal(0, 1, 1, 10, 0) << endl;
}
