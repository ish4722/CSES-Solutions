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

bool check(int mid, vector<int>& machines, int t){
    int total=0;
    for(int i=0;i<machines.size();i++){
        total+=mid/machines[i];
        if(total>=t) return true;
    }
    return false;
}
void solve() {
    int n,t;
    cin>>n>>t;

    vector<int> machines(n);
    f(i,0,n) cin>>machines[i];

    sort(all(machines));

    int low=0,high=machines[n-1]*t;

    while(low<high){
        int mid=(low+high)/2;

        if(check(mid,machines,t)) high=mid;
        else low=mid+1;
    }
    cout<<low<<endl;
}

signed main() {
    ez;

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}