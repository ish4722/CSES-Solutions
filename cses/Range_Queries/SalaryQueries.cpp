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


vector<int> tree, nums, vals;
int n;

void add(int index, int value) {
    while (index <= vals.size()) {
        tree[index] += value;
        index += index & (-index);
    }
}

int prefix(int index) {
    int sum = 0;

    while (index > 0) {
        sum += tree[index];
        index -= index & (-index);
    }

    return sum;
}

void solve() {
    cin >> n;

    int q;
    cin >> q;

    nums.assign(n + 1, 0);

    // Initial salaries
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
        vals.push_back(nums[i]);
    }

    // Store queries because we need all possible salaries
    vector<tuple<char, int, int>> queries;

    for (int i = 0; i < q; i++) {
        char type;
        int a, b;

        cin >> type >> a >> b;

        queries.push_back({type, a, b});

        // New salary that can appear
        if (type == '!') {
            vals.push_back(b);
        }
    }

    // Coordinate compression
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    n = vals.size();
    tree.assign(n + 1, 0);

    // Add initial salaries to Fenwick tree
    for (int i = 1; i < nums.size(); i++) {
        int idx = lower_bound(vals.begin(), vals.end(), nums[i])
                  - vals.begin() + 1;

        add(idx, 1);
    }

    // Process queries
    for (auto [type, a, b] : queries) {

        if (type == '!') {

            // Employee a changes salary nums[a] -> b

            int oldIdx = lower_bound(vals.begin(), vals.end(), nums[a])
                         - vals.begin() + 1;

            int newIdx = lower_bound(vals.begin(), vals.end(), b)
                         - vals.begin() + 1;

            // Remove old salary
            add(oldIdx, -1);

            // Add new salary
            add(newIdx, 1);

            nums[a] = b;
        }

        else {

            // Number of salaries in [a, b]

            // First compressed index with value >= a
            int left = lower_bound(vals.begin(), vals.end(), a)
                       - vals.begin();

            // Number of values <= b
            int right = upper_bound(vals.begin(), vals.end(), b)
                        - vals.begin();

            cout << prefix(right) - prefix(left) << '\n';
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