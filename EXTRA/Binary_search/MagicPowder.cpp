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


bool check(vector<int> &a, vector<int> &b, int k, int mid){
  for(int i=0;i<a.size();i++){
    if(a[i]*mid > b[i] && k>0){
      k-=(a[i]*mid - b[i]);
      if(k<0) return false;
    }
    else if(a[i]*mid > b[i] && k<=0) return false;
  }
    return true;
}
void solve() {
    int n,k;
    cin >> n >> k;

    getv(a,n);
    getv(b,n);

    int low=0,high=2000000005,ans=0;

    while(low<=high){
        int mid=(low+high)/2;

        if(!check(a,b,k,mid)){
            high=mid-1;
        }
        else {
            ans=mid;
            low=mid+1;
        }
    }
    cout<<ans<<endl;
}

signed main() {
    ez;

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}