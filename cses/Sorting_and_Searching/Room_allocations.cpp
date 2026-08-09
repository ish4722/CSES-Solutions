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

    vector<tuple<int,int,int>> customers;

    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        customers.push_back({a,b,i});
    }

    sort(all(customers));//sorted by arrival time as it matter for next customer

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> ans(n);
    int rooms=0;

    for(auto [a,b,idx] : customers){//if arrival >departure the room will be free
        if(!pq.empty() && pq.top().first <a){// that room can be reused
            auto [end_time, room_number] = pq.top(); // departure,room_no
            pq.pop();
            ans[idx] = room_number;
            pq.push({b, room_number});
        }
        else{
            rooms++;
            ans[idx] = rooms;
            pq.push({b, rooms});
        }
    }
    cout << rooms << endl;
    for(int i=0;i<n;i++){
        cout << ans[i] << " ";
    }

}

signed main() {
    ez;

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}