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

int cal(int i,int prev,vector<int>& v,vector<vector<int>>& dp){
    if(i==v.size()) return 0;
    if(dp[i][prev+1]!=-1) return dp[i][prev+1];
    int sum=0;
    sum=max(cal(i+1,prev,v,dp), (prev==-1 || v[i]>v[prev])? 1+cal(i+1,i,v,dp) : 0);
    return dp[i][prev+1]= sum;
}
void solve() {
    int n;
    cin>>n;
    getv(v, n);
    // vector<vector<int>> dp(n,vector<int>(n+1,-1));
    // cout<<cal(0,-1,v,dp)<<endl;
    vector<int> dp(n, 1);
    f(i,0,n){
        f(j,0,i){
            if(v[i]>v[j]) dp[i]=max(dp[i],1+dp[j]);
        }
    }
//this point is good to remember, we have to find the maximum of the dp array, not just the last element, because the longest increasing subsequence can end at any index, not necessarily the last one.
    cout<<*max_element(all(dp))<<endl;

}

// crazy approach for resucing complexity : very good to remember,
//we can use binary search to find the position of the current element in the lis array,
//if it is greater than all elements in the lis array, we can add it to the end of the lis array,
//therwise we can replace the element at the found position with the current element, this way we can maintain the increasing order of the lis array and also reduce the complexity to O(n log n).
void solve2() {
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];

    vector<int> lis;

    for(int x : v){
        auto it = lower_bound(lis.begin(), lis.end(), x);
        if(it == lis.end())
            lis.push_back(x);
        else
            *it = x;
    }

    cout << lis.size() << '\n';
}


signed main() {
    ez;

    int t = 1;
    // cin >> t;
    while (t--) solve2();

    return 0;
}