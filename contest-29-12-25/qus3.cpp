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
    cin>>n;
    getv(a,n);
    getv(b,n);
    getv(c,n);
    int c2 = 0LL;
    for(int k = 0;k < n;k++){
        int c1 = n;
        int j = 0;
        int sec = k;
        
        while(c[sec] > b[j] && c1 > 0 ){
            sec = (sec+1)%n;
            c1--;
            j++;
        }
        if(c1 == 0){
            c2++;
        }
        j = 0;
        
    }
    int c1 = 0LL;
    for(int k = 0;k < n;k++){
        int c3 = n;
        int j = 0;
        int sec = k;
        
        while(b[sec] > a[j] && c3 > 0 ){
            sec = (sec+1)%n;
            c3--;
            j++;
        }
        if(c3 == 0){
            c1++;
        }
        j = 0;
        
    }
    cout<<n*c1*c2*1LL<<endl;
}

signed main() {
    ez;

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}