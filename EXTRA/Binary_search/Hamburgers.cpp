//Binary Sarch ka qus-1600

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

// void solve() {
//     string s;
//     cin >> s;
//     int nb=0,ns=0,nc=0;
//     for (char c : s) {
//         if (c == 'B') nb++;
//         else if (c == 'S') ns++;
//         else nc++;
//     }
//     int pb, ps, pc;
//     cin >> pb >> ps >> pc;
//     int cb, cs, cc;
//     cin >> cb >> cs >> cc;
//     int r;
//     cin >> r;
//     int total = 0;
//     int xx = LLONG_MAX;
//     if (nb) xx = min(xx, pb / nb);
//     if (ns) xx = min(xx, ps / ns);
//     if (nc) xx = min(xx, pc / nc);
//     if (xx == LLONG_MAX) xx = 0;
//     total += xx;
//     pb -= xx * nb;
//     ps -= xx * ns;
//     pc -= xx * nc;

//     while ((pb && nb) || (ps && ns) || (pc && nc)) {
//         int noww = 0;
//         if (pb < nb) { noww += cb * (nb - pb); pb = nb; }
//         if (ps < ns) { noww += cs * (ns - ps); ps = ns; }
//         if (pc < nc) { noww += cc * (nc - pc); pc = nc; }
//         if (noww > r) break;
//         r -= noww;
//         total++;
//         pb -= nb; ps -= ns; pc -= nc;
//     }
//     int aaa = cb * nb + cs * ns + cc * nc;
//     if(aaa) total += r / aaa;
//     cout << total << endl;
// }
void solve() {
    string s;
    cin >> s;
    int nb = 0, ns = 0, nc = 0;
    for (char c : s) {
        if (c == 'B') nb++;
        else if (c == 'S') ns++;
        else nc++;
    }
    
    int pb, ps, pc;
    cin >> pb >> ps >> pc;
    
    int cb, cs, cc;
    cin >> cb >> cs >> cc;
    
    int r;
    cin >> r;

    // Binary Search Space
    int low = 0, high = 1e14 + 100;
    int ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        // Exactly 'mid' burgers banane ki cost nikalte hain
        int req_b = max(0LL, mid * nb - pb);
        int req_s = max(0LL, mid * ns - ps);
        int req_c = max(0LL, mid * nc - pc);
        
        int cost = (req_b * cb) + (req_s * cs) + (req_c * cc);
        
        if (cost <= r) {
            ans = mid;       // Yeh possible hai, isko save kar lo
            low = mid + 1;   // Aur check karo kya isse zyada burgers ban sakte hain?
        } else {
            high = mid - 1;  // Paise kam pad gaye, thode kam burgers try karo
        }
    }

    cout << ans << endl;
}

signed main() {
    ez;

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}