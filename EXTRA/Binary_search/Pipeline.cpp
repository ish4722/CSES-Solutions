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
#define f(i,a,b) for(int i=a; i>b; i--)
#define getv(v, n) vector<int> v(n); f(i,0,n) cin >> v[i];

typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef vector<pair<int,int>> vpi;

const int mod = 1000000007;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int get_sum(int x) {
    return (x * (x + 1)) / 2;
}

bool check(int x, int n, int k) {
    int sum = get_sum(k - 1) - get_sum(k - 1 - x);
    return sum + 1 < n;
}
void solve() {
    int n,k;
    cin >> n >> k;
    if (n == 1) {
        cout << 0 << endl;
        return;
    }

    int low=1,high=k-1,ans=0;
    while(low<=high){
        int mid=(low+high)/2;
        if(check(mid,n,k)) low=mid+1;
        else {high=mid-1; ans=mid;}
    }
    if(ans==0) cout<<-1<<endl;
    else cout << ans << endl;
}

signed main() {
    ez;

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}