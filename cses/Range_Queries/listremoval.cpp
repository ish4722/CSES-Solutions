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

vector<int> tree,nums;
int n;

void add(int value,int index){
    while(index<=n){ tree[index]+=value; index+=index&(-index);} }
int prefix(int index){
    int sum=0;
    while(index>0){
        sum+=tree[index];
        index-=index&(-index);
    }
    return sum;
}
int findKth(int k) {
    int l = 1, r = n;

    while (l < r) {
        int mid = l + (r - l) / 2;

        if (prefix(mid) >= k)
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}
void solve() {
    cin>>n;
    nums.resize(n);
    tree.assign(n + 1, 0);

    for (int i = 0; i < n; i++) cin >> nums[i];

    // Initially every element is alive
    for (int i = 1; i <= n; i++)
        add(1, i);

    // Removals
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;

        int idx = findKth(k);

        cout << nums[idx - 1] << " ";

        // Remove this element
        add(-1, idx);
    }

}

signed main() {
    ez;

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}