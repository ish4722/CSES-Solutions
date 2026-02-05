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

#define int long long

void solve() {
     int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> students;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            students.push_back(i);
        }
    }


    if (students.empty()) {
        cout << (n + 2) / 3 << "\n";
        return;
    }


    int added_students = 0;

    int start_gap = students[0]; 
    added_students += start_gap / 2; 

    added_students = (start_gap + 1) / 3;


    int end_gap = n - 1 - students.back();
    added_students += (end_gap + 1) / 3;

    for (size_t i = 0; i < students.size() - 1; i++) {
        int gap = students[i+1] - students[i] - 1;
        added_students += gap / 3;
    }

    cout << students.size() + added_students << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
