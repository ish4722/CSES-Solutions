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

    vector<pair<int, int>> rooms(n);
    f(i, 0, n) {
        cin >> rooms[i].first >> rooms[i].second;
    }
    sort(all(rooms));

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    int room_count = 0;
    vector<int> room_assignment(n);
    f(i, 0, n) {
        if (!pq.empty() && pq.top().first < rooms[i].first) {
            room_assignment[i] = pq.top().second;
            pq.pop();
        } else {
            room_count++;
            room_assignment[i] = room_count;
        }
        pq.push({rooms[i].second, room_assignment[i]});
    }
    f(i, 0, n) {
        cout << room_assignment[i] << " ";
    }
}

signed main() {
    ez;

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}