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
void add(int index,int val){
        while(index<=n){
            tree[index]+=val;
            index+=index&(-index);
        }
    }

void update(int index,int val){
    int diff=val-nums[index];
    nums[index]=val;
    add(index+1,diff);
}
int prefix(int index){
    int sum=0;
    while(index){
        sum+=tree[index];
        index-=index&(-index);
    }
    return sum;
}
void solve() {
   int q;
   cin>>n>>q;
    tree.resize(n+1,0);
    nums.resize(n,0);
    f(i,0,n){
        cin>>nums[i];
        add(i+1,nums[i]);
    }

    f(i,0,q){
        int type;
        cin>>type;
        if(type==1){
            int index,val;
            cin>>index>>val;
            update(index-1,val);
        }
        else{
            int l,r;
            cin>>l>>r;
            int sum=prefix(r)-prefix(l-1);
            cout<<sum<<endl;
        }
    }
}

signed main() {
    ez;

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}