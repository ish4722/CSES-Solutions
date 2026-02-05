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

const int MOD = 998244353;

/* fast power mod */
int power(int a, int b){
    int res = 1;
    while(b){
        if(b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

/* modular inverse (MOD is prime) */
int inv(int x){
    return power(x, MOD - 2);
}

/* factorial */
int fact(int n){
    int res = 1;
    for(int i = 1; i <= n; i++)
        res = (res * i) % MOD;
    return res;
}

/* nCr */
int nCr(int n, int r){
    if(r < 0 || r > n) return 0;
    int num = fact(n);
    int den = (fact(r) * fact(n - r)) % MOD;
    return (num * inv(den)) % MOD;
}

void solve() {
    int n,k;
    cin >>n >>k;
    string s;
    cin>>s;

    int maxi=0,cnt=0;

    for(int i=0;i<s.size();i++){
        if(s[i]=='1'){
            maxi=i+k+1;
        }
        else if(i>=maxi){
            cnt++;
        }
    }

    cout<< cnt <<endl;
}

signed main() {
    ez;

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}
