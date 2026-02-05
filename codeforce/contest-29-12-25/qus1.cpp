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

// #include "debug.hpp"

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
#define ez ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define int long long
#define all(x) (x).begin(), (x).end()
#define endl "\n"

typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef vector<pair<int,int>> vpi;

const int mod = 1000000007;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }




void solve() {
    int n;
    cin>>n;
    string str;
    cin>>str;

    bool has2026 = false;
    bool has2025 = false;

 for (int i = 0; str[i] != '\0'; i++) {

        if (str[i] == '2' && str[i+1] == '0' &&
            str[i+2] == '2' && str[i+3] == '6') {
            has2026 = true;
        }


        if (str[i] == '2' && str[i+1] == '0' &&
            str[i+2] == '2' && str[i+3] == '5') {
            has2025 = true;
        }
    }
    if(has2026){
        cout<<"0"<<endl;
    }
    else if(has2025){
        cout<<"1"<<endl;
    }
    else{
        cout<<"0"<<endl;
    }

}




signed main() {
    ez;

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

